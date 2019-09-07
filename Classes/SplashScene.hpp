//
//  SplashScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#ifndef SplashScene_hpp
#define SplashScene_hpp

#include "cocos2d.h"

class SplashScene : public cocos2d::Layer
{
private:
    void updateTimer(float dt);
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);
};


#endif /* SplashScene_hpp */
