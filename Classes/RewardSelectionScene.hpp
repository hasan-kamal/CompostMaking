//
//  RewardSelectionScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 08/02/17.
//
//

#ifndef RewardSelectionScene_hpp
#define RewardSelectionScene_hpp

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class RewardSelectionScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void back_callback(cocos2d::Ref* pSender);
    void start_balloon(cocos2d::Ref* pSender);
    void start_fireworks(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(RewardSelectionScene);
};

#endif /* RewardSelectionScene_hpp */
