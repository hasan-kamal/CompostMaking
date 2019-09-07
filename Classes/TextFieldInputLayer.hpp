//
//  TextFieldInputLayer.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#ifndef TextFieldInputLayer_hpp
#define TextFieldInputLayer_hpp

#include <stdio.h>
#include <vector>
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class StartScene;

class TextFieldInputLayer : public cocos2d::Layer
{
private:
    void dismiss();
    bool showing = false;
    TextField *textField;
    
public:
    virtual bool init(StartScene *ss);
    
    // implement the "static create()" method manually
    static TextFieldInputLayer* create(StartScene *ss)
    {
        TextFieldInputLayer *pRet = new(std::nothrow) TextFieldInputLayer();
        if (pRet && pRet->init(ss))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    StartScene *parent_start_scene;
    LayerColor *layer_color;
    
    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    
    void show();
};

#endif /* TextFieldInputLayer_hpp */
