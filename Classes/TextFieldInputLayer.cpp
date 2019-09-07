//
//  TextFieldInputLayer.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#include "TextFieldInputLayer.hpp"
#include "Colors.hpp"
#include "StartScene.hpp"
#include <iostream>

bool TextFieldInputLayer::init(StartScene *ss){
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    parent_start_scene = ss;
    
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
    touchEventListener->onTouchBegan = CC_CALLBACK_2(TextFieldInputLayer::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    float padding = visibleSize.height*5.0/100.0;
    
    //prompt label
    auto prompt_label = Label::createWithTTF("Enter name of student", "fonts/Trirong-Light.ttf", 15);
    prompt_label->setAnchorPoint(Vec2(0.5, 1.0));
    prompt_label->setPosition(Vec2(visibleSize.width/2.0, visibleSize.height*60/100));
    prompt_label->setTextColor(Color4B(Colors::asbestos));
    layer_color->addChild(prompt_label);
    
    //textfield
    textField = TextField::create("NAME","Arial",25);
    textField->setPosition(Vec2(visibleSize.width/2, prompt_label->getPosition().y - prompt_label->getContentSize().height-padding));
    layer_color->addChild(textField);
    
    //button
    auto button = ui::Button::create("");
    button->setTitleText("Submit");
    button->setTitleFontName("fonts/Trirong-Light.ttf");
    button->setTitleFontSize(15);
    button->setAnchorPoint(Vec2(0.5, 1.0));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                parent_start_scene->start(textField->getString());
                this->dismiss();
                break;
            default:
                break;
        }
    });
    button->setTitleColor(Color3B(Colors::asbestos));
    button->setPosition(Vec2(visibleSize.width/2, textField->getPosition().y - textField->getContentSize().height-padding));
    layer_color->addChild(button);
    
    return true;
}

bool TextFieldInputLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    if(showing){
        dismiss();
        return true;
    }
    return false;
}

void TextFieldInputLayer::show(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto move_down = MoveBy::create(0.2, Vec2(0, -1.0*visibleSize.height));
    this->runAction(move_down);
    showing = true;
}

void TextFieldInputLayer::dismiss(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto move_up = MoveBy::create(0.2, Vec2(0, 1.0*visibleSize.height));
    this->runAction(move_up);
    showing = false;
}
