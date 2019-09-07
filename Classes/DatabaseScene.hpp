//
//  DatabaseScene.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 07/05/17.
//
//

#ifndef DatabaseScene_hpp
#define DatabaseScene_hpp

#include "cocos2d.h"
#include "ui/cocosGUI.h"
using namespace cocos2d;
using namespace std;

class DatabaseScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void back_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(DatabaseScene);
};


#endif /* DatabaseScene_hpp */
