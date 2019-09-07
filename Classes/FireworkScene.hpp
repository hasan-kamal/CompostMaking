//
//  FireworkScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 08/02/17.
//
//

#ifndef FireworkScene_hpp
#define FireworkScene_hpp

#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
using namespace std;

class FireworkScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void back_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(FireworkScene);
    int num_times_touched = 0;
    
    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
    
    //particle
    ParticleFireworks *particle_fireworks;
};

#endif /* FireworkScene_hpp */
