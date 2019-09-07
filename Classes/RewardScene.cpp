//
//  RewardScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#include "RewardScene.hpp"
#include "Colors.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

#include <stdlib.h>
#include <time.h>
#include <iostream>

Scene* RewardScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RewardScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RewardScene::init()
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
                                           CC_CALLBACK_1(RewardScene::back_callback, this));
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
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::clouds);
    this->addChild(background);
    
    //label
    auto label = Label::createWithTTF("Balloon Popping Reward", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    this->schedule(schedule_selector(RewardScene::make_balloon), 1.0f);
    srand(time(NULL));
    
    //touch listener
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->onTouchBegan = CC_CALLBACK_2(RewardScene::onTouchBegan, this);
    touchEventListener->onTouchMoved = CC_CALLBACK_2(RewardScene::onTouchMoved, this);
    touchEventListener->onTouchEnded = CC_CALLBACK_2(RewardScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    return true;
}

void RewardScene::make_balloon(float dt){
    
    if(num_balloons_generated>=GlobalSettings::max_balloon_pops)
        return;
    
    string s = "green_balloon.png";
    int r = rand()%4;
    
    if(r==1){
        s = "orange_balloon.png";
    }else if(r==2){
        s = "red_balloon.png";
    }else if(r==3){
        s = "violet_balloon.png";
    }
    
    auto balloon = Sprite::create(s);
    balloon->setScale(Director::getInstance()->getVisibleSize().height*20.0/100.0/balloon->getContentSize().height);
    balloon->setAnchorPoint(Vec2(0.5, 0.5));
    balloon->setPosition(Director::getInstance()->getVisibleOrigin() + (rand()%80 + 10)/100.0*Vec2(Director::getInstance()->getVisibleSize().width, -1*balloon->getContentSize().height*balloon->getScale()));
    
    this->addChild(balloon, 1);
    num_balloons_generated++;
    
    //give it upward velocity
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto up_action = MoveTo::create((3.0 + (rand()%10)/10.0*3.0), Vec2(balloon->getPosition().x, origin.y + visibleSize.height - balloon->getContentSize().height*balloon->getScale()/2));
    balloon->runAction(up_action);
    
    balloons.push_back(balloon);
}

bool RewardScene::is_vector_within_sprite(Sprite *s, Vec2 vector){
    if(s==nullptr)
        return false;
    
    double x1 = s->getPosition().x - s->getContentSize().width*s->getScale()/2;
    double x2 = s->getPosition().x + s->getContentSize().width*s->getScale()/2;
    double y1 = s->getPosition().y - s->getContentSize().height*s->getScale()/2;
    double y2 = s->getPosition().y + s->getContentSize().height*s->getScale()/2;
    
    if(vector.x>x1 && vector.x<x2 && vector.y>y1 && vector.y<y2)
        return true;
    
    return false;
}

void RewardScene::back_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    this->unschedule(schedule_selector(RewardScene::make_balloon));
    Director::getInstance()->popScene();
}

//touch event callbacks
bool RewardScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    std::cout<<"onTouch"<<endl;
    
    for(int i=balloons.size()-1; i>=0; i--){
        if(is_vector_within_sprite(balloons.at(i), touch->getLocation()))
        {
            
            //auto explosion = ParticleExplosion::create();
            auto explosion = ParticleExplosion::createWithTotalParticles(10);
            explosion->setPosition(balloons.at(i)->getPosition());
            this->addChild(explosion);
            
            std::cout<<"touched a sprite"<<endl;
            balloons.at(i)->setVisible(false);
            this->removeChild(balloons.at(i));
            balloons.erase(balloons.begin()+i);
            
            SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::balloon_pop.c_str());
            
            num_popped++;
            if(num_popped>=GlobalSettings::max_balloon_pops)
                this->back_callback(nullptr);
            
            break;
        }
    }
    
    return true;
}

void RewardScene::onTouchMoved(Touch *touch, Event *unused_event){
    
}

void RewardScene::onTouchEnded(Touch *touch, Event *unused_event){
    
}
