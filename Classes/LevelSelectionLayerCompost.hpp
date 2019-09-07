//
//  LevelSelectionLayerCompost.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 04/05/17.
//
//

#ifndef LevelSelectionLayerCompost_hpp
#define LevelSelectionLayerCompost_hpp

#include <stdio.h>
#include <vector>
#include "ui/CocosGUI.h"
#include "Level.hpp"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class GameSceneCompost;

class LevelSelectionLayerCompost : public cocos2d::Layer
{
private:
    void dismiss();
    bool showing = false;
    
public:
    virtual bool init(GameSceneCompost *gs);
    
    // implement the "static create()" method manually
    static LevelSelectionLayerCompost* create(GameSceneCompost *gs)
    {
        LevelSelectionLayerCompost *pRet = new(std::nothrow) LevelSelectionLayerCompost();
        if (pRet && pRet->init(gs))
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
    
    vector<ui::Button *> buttons_for_levels;
    GameSceneCompost *parent_game_scene;
    LayerColor *layer_color;
    
    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    
    void show();
};

#endif /* LevelSelectionLayerCompost_hpp */
