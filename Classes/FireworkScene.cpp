//
//  FireworkScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 08/02/17.
//
//

#include "FireworkScene.hpp"

#include "Colors.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

#include <stdlib.h>
#include <time.h>
#include <iostream>

Scene* FireworkScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FireworkScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool FireworkScene::init()
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
                                           CC_CALLBACK_1(FireworkScene::back_callback, this));
    back_item->setScale(visibleSize.height*6.0/100.0/back_item->getContentSize().height);
    back_item->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    back_item->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(back_item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //background
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::asbestos);
    this->addChild(background);
    
    //label
    auto label = Label::createWithTTF("Fireworks Reward", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::clouds));
    this->addChild(label);
    
    srand(time(NULL));
    
    //touch listener
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->onTouchBegan = CC_CALLBACK_2(FireworkScene::onTouchBegan, this);
    touchEventListener->onTouchMoved = CC_CALLBACK_2(FireworkScene::onTouchMoved, this);
    touchEventListener->onTouchEnded = CC_CALLBACK_2(FireworkScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    return true;
}

void FireworkScene::back_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->popScene();
}

//touch event callbacks
bool FireworkScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    int random_num = rand()%2;
    
    num_times_touched++;
    if(num_times_touched>GlobalSettings::max_fireworks){
        back_callback(nullptr);
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::explosion.c_str());
    
    switch(random_num){
        case 0:{
            auto particle_fireworks = ParticleFireworks::createWithTotalParticles(100 + rand()%500);
            particle_fireworks->setDuration(2.0);
            particle_fireworks->setPosition(touch->getStartLocation());
            particle_fireworks->setVisible(true);
            this->addChild(particle_fireworks);
            break;
            }
        case 1:{
            auto particle_explosion = ParticleExplosion::createWithTotalParticles(100 + rand()%500);
            particle_explosion->setStartColor(Color4F(Colors::alizarin));
            particle_explosion->setDuration(2.0);
            particle_explosion->setPosition(touch->getStartLocation());
            particle_explosion->setVisible(true);
            this->addChild(particle_explosion);
            break;
        }
    }
    
    
    return true;
}

void FireworkScene::onTouchMoved(Touch *touch, Event *unused_event){
    
}

void FireworkScene::onTouchEnded(Touch *touch, Event *unused_event){
    
}
