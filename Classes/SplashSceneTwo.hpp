//
//  SplashSceneTwo.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#ifndef SplashSceneTwo_hpp
#define SplashSceneTwo_hpp

#include "cocos2d.h"

class SplashSceneTwo : public cocos2d::Layer
{
private:
    void updateTimer(float dt);
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SplashSceneTwo);
};

#endif /* SplashSceneTwo_hpp */
