//
//  LevelSelectionLayerCompost.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 04/05/17.
//
//

#include "LevelSelectionLayerCompost.hpp"
#include "Colors.hpp"
#include "GameSceneCompost.hpp"
#include <iostream>

bool LevelSelectionLayerCompost::init(GameSceneCompost *gs){
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    parent_game_scene = gs;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->setAnchorPoint(Vec2(0.0, 0.0));
    this->setPosition(Vec2(origin.x, origin.y + visibleSize.height));
    
    //layer_color
    layer_color = LayerColor::create(Color4B(Colors::cloudsFuzzy), visibleSize.width, visibleSize.height);
    layer_color->setAnchorPoint(Vec2(0.0, 0.0));
    layer_color->setPosition(Vec2(0, 0));
    this->addChild(layer_color);
    
    //touch listener
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->setSwallowTouches(true);
    touchEventListener->onTouchBegan = CC_CALLBACK_2(LevelSelectionLayerCompost::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    //labels for levels
    auto prompt_label = Label::createWithTTF("Select Level", "fonts/Trirong-Light.ttf", 30);
    prompt_label->setAnchorPoint(Vec2(0.5, 0.5));
    prompt_label->setPosition(Vec2(visibleSize.width/2.0, visibleSize.height*60.0/100.0));
    prompt_label->setColor(Color3B(Colors::wet_asphalt));
    layer_color->addChild(prompt_label, 1);
    
    //buttons for levels
    float empty_space = visibleSize.width*10/100;
    for(int i=1; i<=Level::max_level_number; i++){
        char str[10];
        sprintf(str, "%d", i);
        auto button = ui::Button::create("");
        button->setTitleText(str);
        button->setTitleFontName("fonts/Trirong-Light.ttf");
        button->setTitleFontSize(20);
        button->setAnchorPoint(Vec2(0.5, 1.0));
        button->addTouchEventListener([&, i](Ref* sender, Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    parent_game_scene->switch_level(i-1);
                    this->dismiss();
                    break;
                default:
                    break;
            }
        });
        if(Level::max_level_number%2)
            button->setPosition(Vec2(visibleSize.width/2 - ((Level::max_level_number+1)/2-i)*empty_space, visibleSize.height*50.0/100.0));
        else
            button->setPosition(Vec2(visibleSize.width/2 - ((Level::max_level_number+1)/2.0-i)*empty_space, visibleSize.height*50.0/100.0));
        button->setTitleColor(Color3B(Colors::asbestos));
        layer_color->addChild(button);
        buttons_for_levels.push_back(button);
    }
    
    return true;
}

bool LevelSelectionLayerCompost::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    if(showing){
        dismiss();
        return true;
    }
    return false;
}

void LevelSelectionLayerCompost::show(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto move_down = MoveBy::create(0.2, Vec2(0, -1.0*visibleSize.height));
    this->runAction(move_down);
    showing = true;
}

void LevelSelectionLayerCompost::dismiss(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto move_up = MoveBy::create(0.2, Vec2(0, 1.0*visibleSize.height));
    this->runAction(move_up);
    showing = false;
}
