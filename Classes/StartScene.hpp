//
//  StartScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 19/01/17.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
private:
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void settings_callback(cocos2d::Ref* pSender);
    void play_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};


#endif /* StartScene_hpp */
