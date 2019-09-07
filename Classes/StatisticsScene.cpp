//
//  StatisticsScene.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#include "StatisticsScene.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"
#include "RewardScene.hpp"
#include "FireworkScene.hpp"
#include "Colors.hpp"
#include "Level.hpp"
#include "Statistics.hpp"
#include <iostream>

Scene* StatisticsScene::createScene(vector<int> n_c, vector<int> n_ic)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StatisticsScene::create(n_c, n_ic);
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StatisticsScene::init(vector<int> num_correct, vector<int> num_incorrect)
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
                                           CC_CALLBACK_1(StatisticsScene::back_callback, this));
    back_item->setScale(visibleSize.height*6.0/100.0/back_item->getContentSize().height);
    back_item->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    back_item->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
    
    float padding_space = visibleSize.width*10.0/100.0;
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(back_item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //background
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::clouds);
    this->addChild(background);
    
    //label
    std::cout<<Statistics::player_name<<endl;
    auto label = Label::createWithTTF(Statistics::player_name+"(stats)", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.5));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*70.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    //stats label
    auto stats_label = Label::createWithTTF("#level: incorrect, total, accuracy", "fonts/Trirong-Light.ttf", 13);
    stats_label->setAnchorPoint(Vec2(0.0, 0.5));
    stats_label->setPosition(Vec2(origin.x + visibleSize.width*25.0/100.0,
                            origin.y + visibleSize.height*60.0/100.0));
    stats_label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(stats_label);
    
    //display level_wise
    Vec2 last_pos = stats_label->getPosition();
    Vec2 diff = Vec2(0, visibleSize.height*5.0/100.0);
    char buffer[100];
    for(int i=0; i<Level::max_level_number; i++){
        if(num_correct[i]+num_incorrect[i]==0)
            sprintf(buffer, "#%d: %9d, %5d, --.--%%", i+1, num_incorrect[i], num_incorrect[i]+num_correct[i]);
        else
            sprintf(buffer, "#%d: %9d, %5d, %2.2f%%", i+1, num_incorrect[i], num_incorrect[i]+num_correct[i], (num_correct[i])/(num_correct[i]+num_incorrect[i]+0.0)*100.0);
        auto l = Label::createWithTTF(buffer, "fonts/Trirong-Light.ttf", 10);
        l->setAnchorPoint(Vec2(0.0, 0.5));
        last_pos = last_pos - diff;
        l->setPosition(last_pos);
        l->setTextColor(Color4B(Colors::asbestos));
        this->addChild(l);
    }
    
    return true;
}

void StatisticsScene::back_callback(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->popScene();
}
