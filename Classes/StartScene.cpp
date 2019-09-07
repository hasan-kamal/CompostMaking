//
//  StartScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 19/01/17.
//
//

#include "StartScene.hpp"
#include "GameScene.hpp"
#include "GameSceneCompost.hpp"
#include "Colors.hpp"
#include <iostream>
#include "SimpleAudioEngine.h"
#include "GlobalSettings.hpp"
#include "SettingsScene.hpp"
#include "Statistics.hpp"
#include "DatabaseScene.hpp"

using namespace cocos2d;
using namespace std;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "close_thin.png",
                                           "close_thin.png",
                                           CC_CALLBACK_1(StartScene::menuCloseCallback, this));
    closeItem->setScale(visibleSize.height*6.0/100.0/closeItem->getContentSize().height);
    closeItem->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
    
    auto db_item = MenuItemImage::create("db_icon.png", "db_icon.png", CC_CALLBACK_1(StartScene::db_callback, this));
    db_item->setAnchorPoint(Vec2(0.0, 0.0));
    db_item->setScale(visibleSize.height*6.0/100.0/db_item->getContentSize().height);
    db_item->setPosition(Vec2(origin.x + padding, origin.y + padding));
    
    auto settings_item = MenuItemImage::create("settings.png", "settings.png", CC_CALLBACK_1(StartScene::settings_callback, this));
    settings_item->setAnchorPoint(Vec2(0.0, 0.0));
    settings_item->setScale(visibleSize.height*6.0/100.0/settings_item->getContentSize().height);
    settings_item->setPosition(Vec2(origin.x + db_item->getContentSize().width*db_item->getScale() + padding*2.0, origin.y + padding));
    
    auto play_compost_item = MenuItemImage::create("resume.png", "resume.png", CC_CALLBACK_1(StartScene::play_compost_callback, this));
    play_compost_item->setAnchorPoint(Vec2(0.5, 0.5));
    play_compost_item->setScale(visibleSize.height*15.0/100/play_compost_item->getContentSize().height);
    play_compost_item->setOpacity(150);
    play_compost_item->setPosition(Vec2(origin.x + visibleSize.width*67.0/100, origin.y + visibleSize.height*25.0/100.0));
    
    auto play_bio_item = MenuItemImage::create("resume.png", "resume.png", CC_CALLBACK_1(StartScene::play_bio_callback, this));
    play_bio_item->setAnchorPoint(Vec2(0.5, 0.5));
    play_bio_item->setScale(visibleSize.height*15.0/100/play_bio_item->getContentSize().height);
    play_bio_item->setOpacity(150);
    play_bio_item->setPosition(Vec2(origin.x + visibleSize.width*33.0/100, origin.y + visibleSize.height*25.0/100.0));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, db_item, settings_item, play_compost_item, play_bio_item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::clouds);
    this->addChild(background);
    
    auto sprite_logo = Sprite::create("iiitd_logo_alpha.png");
    sprite_logo->setScale(visibleSize.height*12.0/100.0/sprite_logo->getContentSize().height);
    sprite_logo->setAnchorPoint(Vec2(0.5, 0.5));
    sprite_logo->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    //label
    auto label = Label::createWithTTF("CompostMaking", "fonts/Trirong-Light.ttf", 30);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    //version
    auto version_label = Label::createWithTTF("v4(beta)", "fonts/Trirong-Light.ttf", 10);
    version_label->setAnchorPoint(Vec2(0.5, 1.0));
    version_label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*75/100));
    version_label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(version_label);
    
    //prompt
    auto prompt_label = Label::createWithTTF("*Select Mode*", "fonts/Trirong-Light.ttf", 13);
    prompt_label->setAnchorPoint(Vec2(0.5, 1.0));
    prompt_label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*70/100));
    prompt_label->setTextColor(Color4B(Colors::asbestos));
    //this->addChild(prompt_label);
    
    //pot sprite
    auto pot_sprite = Sprite::create("brown_pot_png.png");
    pot_sprite->setScale(visibleSize.height*25.0/100.0/pot_sprite->getContentSize().height);
    pot_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    pot_sprite->setPosition(Vec2(origin.x + visibleSize.width*67.0/100.0, origin.y + visibleSize.height/2));
    this->addChild(pot_sprite);
    
    //pot label
    auto compost_label = Label::createWithTTF("compost/non-compost mode", "fonts/Trirong-Light.ttf", 10);
    compost_label->setAnchorPoint(Vec2(0.5, 1.0));
    compost_label->setPosition(Vec2(origin.x + visibleSize.width*67.0/100.0, origin.y + visibleSize.height*38/100));
    compost_label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(compost_label);
    
    //leaf sprite
    auto leaf_sprite = Sprite::create("green_blue_tray.png");
    leaf_sprite->setScale(visibleSize.height*23.0/100.0/leaf_sprite->getContentSize().height);
    leaf_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    leaf_sprite->setPosition(Vec2(origin.x + visibleSize.width*33.0/100.0, origin.y + visibleSize.height/2));
    this->addChild(leaf_sprite);
    
    //pot label
    auto bio_label = Label::createWithTTF("biodeg/non-biodeg mode", "fonts/Trirong-Light.ttf", 10);
    bio_label->setAnchorPoint(Vec2(0.5, 1.0));
    bio_label->setPosition(Vec2(origin.x + visibleSize.width*33.0/100.0, origin.y + visibleSize.height*38/100));
    bio_label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(bio_label);
    
    //textFieldInputLayer
    textFieldInputLayer = TextFieldInputLayer::create(this);
    this->addChild(textFieldInputLayer, 5);
    
    cout<<endl;
    cout<<Statistics::get_stat()<<endl;
    
    return true;
}

void StartScene::settings_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto settingsScene = SettingsScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(1.0, settingsScene, Color3B(Colors::clouds)));
}

void StartScene::db_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto dbScene = DatabaseScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(1.0, dbScene, Color3B(Colors::clouds)));
}

void StartScene::play_compost_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    bio_mode = false;
    Statistics::player_name="";
    textFieldInputLayer->show();
    //auto gameSceneCompost = GameSceneCompost::createScene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameSceneCompost, Color3B(Colors::clouds)));
}

void StartScene::play_bio_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    bio_mode = true;
    Statistics::player_name="";
    textFieldInputLayer->show();
    //auto gameScene = GameScene::createScene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameScene, Color3B(Colors::clouds)));
}

void StartScene::start(string student_name){
    cout<<student_name<<endl;
    Statistics::player_name = student_name;
    if(bio_mode){
        Statistics::is_bio = true;
        auto gameScene = GameScene::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameScene, Color3B(Colors::clouds)));
    }else{
        Statistics::is_bio = false;
        auto gameSceneCompost = GameSceneCompost::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameSceneCompost, Color3B(Colors::clouds)));
    }
}

void StartScene::menuCloseCallback(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
