//
//  SplashScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#include "SplashScene.hpp"
#include "StartScene.hpp"
#include "Colors.hpp"
#include <iostream>

using namespace cocos2d;
using namespace std;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
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
    
    
    auto sprite_logo = Sprite::create("iiitd_logo_alpha.png");
    sprite_logo->setScale(visibleSize.height*8.0/100.0/sprite_logo->getContentSize().height);
    sprite_logo->setAnchorPoint(Vec2(0.5, 0.5));
    sprite_logo->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    
    this->addChild(sprite_logo);
    this->schedule(schedule_selector(SplashScene::updateTimer), 3.0f);
    
    return true;
}

void SplashScene::updateTimer(float dt){
    this->unschedule(schedule_selector(SplashScene::updateTimer));
    
    auto startScene = StartScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, startScene, Color3B(Colors::clouds)));
}
