//
//  CharacterLayer.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#include "CharacterLayer.hpp"
#include "Colors.hpp"
#include "SimpleAudioEngine.h"
#include "GlobalSettings.hpp"
#include <iostream>

using namespace cocos2d;
using namespace spine;
using namespace std;

bool CharacterLayer::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //elf
    elf = SkeletonAnimation::createWithFile("skeleton.json", "skeleton.atlas", 0.6f);
    elf->setScale(0.25);
    
    vector<string> anims{"standing", "sad_expression", "happy_jump", "prompt"};
    
    for(int i = 0; i<anims.size(); i++){
        for(int j=0; j<anims.size(); j++){
            if(i==j)
                continue;
            elf->setMix(anims.at(i), anims.at(j), 0.2f);
        }
    }
    
    elf->setAnimation(0, "standing", true);
    //spTrackEntry* promptEntry = elf->addAnimation(0, "prompt", false, 3);
    //elf->addAnimation(0, "standing", true);
    
    float padding = visibleSize.height*10.0/100;
    float height = visibleSize.height*28/100;
    float width = height*100.0/253.0;
    
    //elf->setAnchorPoint(Vec2(0.0, 1.0));
    elf->setPosition(Vec2(origin.x + width/2 + padding, origin.y + visibleSize.height - padding - height));
    addChild(elf, 1);
    
    //speech_bubble
    speech_bubble = Sprite::create("speech_bubble.png");
    speech_bubble->setScale(visibleSize.height*20.0/100.0/speech_bubble->getContentSize().height);
    speech_bubble->setPosition(Vec2(0.0, 0.0));
    speech_bubble->setPosition(elf->getPosition()+Vec2(width + padding/2, height));
    speech_bubble->setVisible(false);
    this->addChild(speech_bubble);
    
    //Label
    bubble_label = Label::createWithTTF("", "fonts/Trirong-Light.ttf", 10);
    bubble_label->setColor(Color3B(Colors::wet_asphalt));
    bubble_label->setVisible(false);
    this->addChild(bubble_label);
    
    return true;
}

void CharacterLayer::show_standing(){
    hide_speech_bubble();
    elf->setAnimation(0, "standing", true);
}

void CharacterLayer::show_sad_expression(){
    hide_speech_bubble();
    elf->setAnimation(0, "sad_expression", false);
}

void CharacterLayer::show_happy_jump(){
    hide_speech_bubble();
    elf->setAnimation(0, "happy_jump", false);
}

void CharacterLayer::show_prompt(){
    //elf->addAnimation(0, "prompt", false, 3);
    elf->setAnimation(0, "prompt", false);
    show_speech_bubble("Come on!\nYou can do it !");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::prompt.c_str());
}

void CharacterLayer::show_speech_bubble(string speech){
    bubble_label->setString(speech);
    bubble_label->setPosition(speech_bubble->getPosition());
    bubble_label->setVisible(true);
    speech_bubble->setVisible(true);
}

void CharacterLayer::hide_speech_bubble(){
    bubble_label->setVisible(false);
    speech_bubble->setVisible(false);
}
