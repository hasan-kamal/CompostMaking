//
//  SettingsScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 03/03/17.
//
//

#include "SettingsScene.hpp"
#include "GlobalSettings.hpp"
#include "SimpleAudioEngine.h"
#include "Colors.hpp"
#include <iostream>

using namespace cocos2d::ui;

Scene* SettingsScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SettingsScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SettingsScene::init()
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
                                           CC_CALLBACK_1(SettingsScene::back_callback, this));
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
    auto label = Label::createWithTTF("Settings", "fonts/Trirong-Light.ttf", 20);
    label->setAnchorPoint(Vec2(0.5, 0.0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*80.0/100.0));
    label->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label);
    
    /*
     //following are editable via settings scene
     const int GlobalSettings::max_num_wrong_attempt = 6;
     const int GlobalSettings::language_preference_english = 1;
     const bool GlobalSettings::hint_enable = true;
     */
    
    float padding_vertical = visibleSize.height*1.0/100.0;
    
    //label_feedback
    auto label_feedback = Label::createWithTTF("feedback enable:", "fonts/Trirong-Light.ttf", 10);
    label_feedback->setAnchorPoint(Vec2(0.5, 0.0));
    label_feedback->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*65.0/100.0));
    label_feedback->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label_feedback);
    
    //checkbox_feedback_enable
    auto checkbox_feedback_enable = CheckBox::create("checkbox_empty.png",
                                                     "checkbox.png");
    checkbox_feedback_enable->setSelected(GlobalSettings::feedback_enable);
    checkbox_feedback_enable->setAnchorPoint(Vec2(0.5, 1.0));
    std::cout<<"checkbox_feedback_enable "<<GlobalSettings::feedback_enable<<endl<<endl;
    checkbox_feedback_enable->addTouchEventListener([&, checkbox_feedback_enable](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                GlobalSettings::feedback_enable = checkbox_feedback_enable->isSelected();
                std::cout<<"checkbox_feedback_enable "<<GlobalSettings::feedback_enable<<endl<<endl;
                break;
            default:
                break;
        }
    });
    checkbox_feedback_enable->setScale(visibleSize.height*5.0/100.0/checkbox_feedback_enable->getContentSize().height);
    checkbox_feedback_enable->setPosition(label_feedback->getPosition() - Vec2(0,
                                                                               1.0*padding_vertical));
    this->addChild(checkbox_feedback_enable);
    
    //label_hint
    auto label_hint = Label::createWithTTF("hint enable:", "fonts/Trirong-Light.ttf", 10);
    label_hint->setAnchorPoint(Vec2(0.5, 0.0));
    label_hint->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*50.0/100.0));
    label_hint->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label_hint);
    
    //checkbox_hint_enable
    auto checkbox_hint = CheckBox::create("checkbox_empty.png",
                                     "checkbox.png");
    checkbox_hint->setSelected(GlobalSettings::hint_enable);
    checkbox_hint->setAnchorPoint(Vec2(0.5, 1.0));
    std::cout<<"hint_enable "<<GlobalSettings::hint_enable<<endl<<endl;
    checkbox_hint->addTouchEventListener([&, checkbox_hint](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                GlobalSettings::hint_enable = checkbox_hint->isSelected();
                std::cout<<"hint_enable "<<GlobalSettings::hint_enable<<endl<<endl;
                break;
            default:
                break;
        }
    });
    checkbox_hint->setScale(visibleSize.height*5.0/100.0/checkbox_hint->getContentSize().height);
    checkbox_hint->setPosition(label_hint->getPosition() - Vec2(0,
                                    1.0*padding_vertical));
    this->addChild(checkbox_hint);
    
    
    //label_language
    auto label_language = Label::createWithTTF("language english:", "fonts/Trirong-Light.ttf", 10);
    label_language->setAnchorPoint(Vec2(0.5, 0.0));
    label_language->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*35.0/100.0));
    label_language->setTextColor(Color4B(Colors::asbestos));
    this->addChild(label_language);
    
    //checkbox_language_pref
    auto checkbox_language_pref = CheckBox::create("checkbox_empty.png",
                                          "checkbox.png");
    checkbox_language_pref->setSelected(GlobalSettings::language_preference_english);
    checkbox_language_pref->setAnchorPoint(Vec2(0.5, 1.0));
    checkbox_language_pref->addTouchEventListener([&, checkbox_language_pref](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                GlobalSettings::language_preference_english = checkbox_language_pref->isSelected();
                break;
            default:
                break;
        }
    });
    checkbox_language_pref->setScale(visibleSize.height*5.0/100.0/checkbox_language_pref->getContentSize().height);
    checkbox_language_pref->setPosition(label_language->getPosition() - Vec2(0,
                                                                1.0*padding_vertical));
    this->addChild(checkbox_language_pref);
    
    return true;
}

void SettingsScene::back_callback(cocos2d::Ref* pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    Director::getInstance()->popScene();
}
