//
//  DatabaseScene.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 07/05/17.
//
//

#include "DatabaseScene.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"
#include "Colors.hpp"
#include "Statistics.hpp"
#include <iostream>

using namespace cocos2d::ui;

Scene* DatabaseScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DatabaseScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DatabaseScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //closeItem
    auto closeItem = MenuItemImage::create(
                                           "left_angle.png",
                                           "left_angle.png",
                                           CC_CALLBACK_1(DatabaseScene::back_callback, this));
    closeItem->setScale(visibleSize.height*6.0/100.0/closeItem->getContentSize().height);
    closeItem->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //background
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::clouds);
    this->addChild(background);
    
    //label
    auto label = Label::createWithTTF("Statistics Log", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*90.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    //format label
    auto format = Label::createWithTTF("#level: incorrect, total, accuracy", "fonts/Trirong-Light.ttf", 10);
    format->setAnchorPoint(Vec2(0.0, 1.0));
    format->setPosition(Vec2(origin.x, origin.y + visibleSize.height*90.0/100.0));
    format->setTextColor(Color4B(Colors::asbestos));
    this->addChild(format);
    
    //text
    auto textWidget = Text::create();
    textWidget->setText(Statistics::get_stat());
    textWidget->setFontName("fonts/Roboto-Light.ttf");
    textWidget->setFontSize(10);
    textWidget->setAnchorPoint(Vec2(0.5, 0.5));
    textWidget->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.width/2));
    textWidget->setColor(Color3B(Colors::clouds));
    
    //scrollview
    Size scrollFrameSize = Size(visibleSize.width *100.0/100.0, visibleSize.height *70.0/100.0);
    auto scrollView = ScrollView::create();
    scrollView->setBackGroundColorType(LAYOUT_COLOR_SOLID);
    scrollView->setBackGroundColor(Color3B(Colors::asbestos));
    scrollView->setSize(scrollFrameSize);
    scrollView->setAnchorPoint(Vec2(0.5, 0.5));
    scrollView->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    scrollView->setDirection(SCROLLVIEW_DIR_VERTICAL);
    
    auto containerSize = Size(scrollFrameSize.width, textWidget->getContentSize().height);
    scrollView->setInnerContainerSize(containerSize);
    
    scrollView->setLayoutType(LAYOUT_LINEAR_VERTICAL);
    scrollView->addChild(textWidget);
    this->addChild(scrollView);
    
    return true;
}

void DatabaseScene::back_callback(cocos2d::Ref* pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->popScene();
}
