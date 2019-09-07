//
//  SplashSceneTwo.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#include "SplashSceneTwo.hpp"
#include "StartScene.hpp"
#include "Colors.hpp"
#include <iostream>

using namespace cocos2d;
using namespace std;

Scene* SplashSceneTwo::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashSceneTwo::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashSceneTwo::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::white);
    this->addChild(background);
    
    //ngo_logo
    auto ngo_logo = Sprite::create("tamana_trimed_logo.png");
    ngo_logo->setScale(visibleSize.height*12.0/100.0/ngo_logo->getContentSize().height);
    ngo_logo->setAnchorPoint(Vec2(0.5, 0.5));
    ngo_logo->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*55.0/100.0));
    
    //association_label
    auto association_label = Label::createWithTTF("in association with", "fonts/Roboto-Light.ttf", 8);
    association_label->setAnchorPoint(Vec2(0.5, 1.0));
    association_label->setPosition(Vec2(origin.x + visibleSize.width/2.0, origin.y + visibleSize.height*38.0/100.0));
    association_label->setTextColor(Color4B(Colors::wet_asphalt));
    //association_label->setOpacity(0);
    this->addChild(association_label);
    
    //ministry_label
    auto ministry_label = Label::createWithTTF("MINISTRY OF SOCIAL JUSTICE AND EMPOWERMENT", "fonts/Roboto-Light.ttf", 10);
    ministry_label->setAnchorPoint(Vec2(0.5, 1.0));
    ministry_label->setPosition(Vec2(origin.x + visibleSize.width/2.0, origin.y + visibleSize.height*35.0/100.0));
    ministry_label->setTextColor(Color4B(Colors::wet_asphalt));
    //ministry_label->setOpacity(0);
    this->addChild(ministry_label);
    
    //fadeIn
//    auto fadeInAction = FadeIn::create(0.5);
//    ministry_label->runAction(fadeInAction);
//    association_label->runAction(fadeInAction->clone());
    
    this->addChild(ngo_logo);
    this->schedule(schedule_selector(SplashSceneTwo::updateTimer), 2.0f);
    
    return true;
}

void SplashSceneTwo::updateTimer(float dt){
    this->unschedule(schedule_selector(SplashSceneTwo::updateTimer));
    
    auto startScene = StartScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, startScene, Color3B(Colors::clouds)));
}
