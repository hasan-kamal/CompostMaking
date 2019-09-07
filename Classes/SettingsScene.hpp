//
//  SettingsScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 03/03/17.
//
//

#ifndef SettingsScene_hpp
#define SettingsScene_hpp

#include "cocos2d.h"
#include "ui/cocosGUI.h"
using namespace cocos2d;
using namespace std;

class SettingsScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void back_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingsScene);
};

#endif /* SettingsScene_hpp */
