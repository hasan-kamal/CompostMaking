//
//  CharacterLayer.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#ifndef CharacterLayer_hpp
#define CharacterLayer_hpp

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
using namespace cocos2d;
using namespace std;

class CharacterLayer : public cocos2d::Layer
{
private:
    spine::SkeletonAnimation *elf;
    Sprite *speech_bubble;
    Label *bubble_label;
    void show_speech_bubble(string speech);
    void hide_speech_bubble();

public:
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(CharacterLayer);
    
    void show_standing();
    void show_sad_expression();
    void show_happy_jump();
    void show_prompt();
};


#endif /* CharacterLayer_hpp */
