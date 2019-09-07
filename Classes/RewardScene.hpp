//
//  RewardScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#ifndef RewardScene_hpp
#define RewardScene_hpp

#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
using namespace std;

class RewardScene : public cocos2d::Layer
{
private:
    static bool is_vector_within_sprite(Sprite *sprite, Vec2 vector);
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void back_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(RewardScene);
    
    void make_balloon(float dt);
    vector<Sprite *> balloons;
    int num_popped = 0;
    int num_balloons_generated = 0;
    
    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif /* RewardScene_hpp */
