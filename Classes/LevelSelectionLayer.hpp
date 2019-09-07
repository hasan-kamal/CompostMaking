//
//  LevelSelectionLayer.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 03/03/17.
//
//

#ifndef LevelSelectionLayer_hpp
#define LevelSelectionLayer_hpp

#include <stdio.h>
#include <vector>
#include "ui/CocosGUI.h"
#include "Level.hpp"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class GameScene;

class LevelSelectionLayer : public cocos2d::Layer
{
private:
    void dismiss();
    bool showing = false;
    
public:
    virtual bool init(GameScene *gs);
    
    // implement the "static create()" method manually
    static LevelSelectionLayer* create(GameScene *gs)
    {
        LevelSelectionLayer *pRet = new(std::nothrow) LevelSelectionLayer();
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
    GameScene *parent_game_scene;
    LayerColor *layer_color;
    
    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    
    void show();
};


#endif /* LevelSelectionLayer_hpp */
