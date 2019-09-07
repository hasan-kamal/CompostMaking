//
//  StartScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 19/01/17.
//
//

#include "StartScene.hpp"
#include "GameScene.hpp"
#include "Colors.hpp"
#include <iostream>
#include "SimpleAudioEngine.h"
#include "GlobalSettings.hpp"

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
    
    auto settings_item = MenuItemImage::create("settings.png", "settings.png", CC_CALLBACK_1(StartScene::settings_callback, this));
    settings_item->setAnchorPoint(Vec2(0.0, 0.0));
    settings_item->setScale(visibleSize.height*6.0/100.0/settings_item->getContentSize().height);
    settings_item->setPosition(Vec2(origin.x + padding, origin.y + padding));
    
    auto play_item = MenuItemImage::create("resume.png", "resume.png", CC_CALLBACK_1(StartScene::play_callback, this));
    play_item->setAnchorPoint(Vec2(0.5, 0.5));
    play_item->setScale(visibleSize.height*15.0/100/play_item->getContentSize().height);
    play_item->setOpacity(150);
    play_item->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*25.0/100.0));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, settings_item, play_item, NULL);
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
    auto label = Label::createWithTTF("Compost Identification", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    //pot sprite
    auto pot_sprite = Sprite::create("brown_pot_png.png");
    pot_sprite->setScale(visibleSize.height*30.0/100.0/pot_sprite->getContentSize().height);
    pot_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    pot_sprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    this->addChild(pot_sprite);
    
    return true;
}

void StartScene::settings_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
}

void StartScene::play_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameScene, Color3B(Colors::clouds)));
}

void StartScene::menuCloseCallback(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
