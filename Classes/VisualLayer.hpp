//
//  VisualLayer.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#ifndef VisualLayer_hpp
#define VisualLayer_hpp

#include "cocos2d.h"
using namespace cocos2d;

class VisualLayer : public cocos2d::Layer
{
private:
    Sprite *smiley, *sad;
    
public:
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(VisualLayer);
    
    void show_happy_face();
    void show_sad_face();
};

#endif /* VisualLayer_hpp */
