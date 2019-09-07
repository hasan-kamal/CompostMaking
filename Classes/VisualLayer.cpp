//
//  VisualLayer.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#include "VisualLayer.hpp"
using namespace cocos2d;

bool VisualLayer::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //smiley
    smiley = Sprite::create("smiley.png");
    smiley->setOpacity(0);
    smiley->setScale(visibleSize.height*15/100/smiley->getContentSize().height);
    smiley->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    this->addChild(smiley, 1);
    
    //sad
    sad = Sprite::create("sad.png");
    sad->setOpacity(0);
    sad->setScale(visibleSize.height*15/100/sad->getContentSize().height);
    sad->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    this->addChild(sad, 1);
    
    return true;
}

void VisualLayer::show_happy_face(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    sad->setVisible(false);
    smiley->setVisible(true);
    smiley->setOpacity(255);
    smiley->setScale(visibleSize.height*15/100/smiley->getContentSize().height);
    smiley->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    
    auto scale_up = ScaleBy::create(2.0, 2.0);
    auto fade_out = FadeOut::create(2.0);
    
    smiley->runAction(scale_up);
    smiley->runAction(fade_out);
}

void VisualLayer::show_sad_face(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    smiley->setVisible(false);
    sad->setVisible(true);
    sad->setOpacity(255);
    sad->setScale(visibleSize.height*15/100/sad->getContentSize().height);
    sad->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    
    auto scale_up = ScaleBy::create(2.0, 2.0);
    auto fade_out = FadeOut::create(2.0);
    
    sad->runAction(scale_up);
    sad->runAction(fade_out);
}
