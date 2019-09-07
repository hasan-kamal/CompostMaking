//
//  RewardSelectionScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 08/02/17.
//
//

#include "RewardSelectionScene.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"
#include "RewardScene.hpp"
#include "FireworkScene.hpp"
#include "Colors.hpp"

Scene* RewardSelectionScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RewardSelectionScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RewardSelectionScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //back_item
    auto back_item = MenuItemImage::create(
                                           "left_angle.png",
                                           "left_angle.png",
                                           CC_CALLBACK_1(RewardSelectionScene::back_callback, this));
    back_item->setScale(visibleSize.height*6.0/100.0/back_item->getContentSize().height);
    back_item->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    back_item->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
    
    float padding_space = visibleSize.width*10.0/100.0;
    
    //balloon item
    auto balloon_item = MenuItemImage::create(
                                           "balloon_icon_black.png",
                                           "balloon_icon_black.png",
                                           CC_CALLBACK_1(RewardSelectionScene::start_balloon, this));
    balloon_item->setScale(visibleSize.height*30.0/100.0/balloon_item->getContentSize().height);
    balloon_item->setAnchorPoint(Vec2(1.0, 0.5));
    balloon_item->setPosition(Vec2(origin.x + visibleSize.width/2.0 - padding_space,
                                origin.y + visibleSize.height/2.0));
    auto fadeOut = FadeTo::create(0.5f, 200);
    auto fadeIn = FadeTo::create(0.5f, 255);
    auto seq = Sequence::create(fadeOut, fadeIn, NULL);
    auto repeatSeq = RepeatForever::create(seq);
    balloon_item->runAction(repeatSeq);
    
    
    //firework item
    auto firework_item = MenuItemImage::create(
                                              "bomb_icon_black.png",
                                              "bomb_icon_black.png",
                                              CC_CALLBACK_1(RewardSelectionScene::start_fireworks, this));
    firework_item->setScale(visibleSize.height*20.0/100.0/firework_item->getContentSize().height);
    firework_item->setAnchorPoint(Vec2(0.0, 0.5));
    firework_item->setPosition(Vec2(origin.x + visibleSize.width/2.0 + padding_space,
                                   origin.y + visibleSize.height/2.0));
    firework_item->runAction(repeatSeq->clone());

    
    // create menu, it's an autorelease object
    auto menu = Menu::create(back_item, balloon_item, firework_item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //background
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::clouds);
    this->addChild(background);
    
    //label
    auto label = Label::createWithTTF("Select Reward!", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    return true;
}

void RewardSelectionScene::start_balloon(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto balloon_scene = RewardScene::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.5f, balloon_scene, Color3B(Colors::clouds)));
}

void RewardSelectionScene::start_fireworks(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto firework_scene = FireworkScene::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.5f, firework_scene, Color3B(Colors::clouds)));
}

void RewardSelectionScene::back_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->popScene();
}
