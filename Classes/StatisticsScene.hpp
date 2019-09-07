//
//  StatisticsScene.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#ifndef StatisticsScene_hpp
#define StatisticsScene_hpp

#include "cocos2d.h"
#include <vector>
#include <string>
using namespace cocos2d;
using namespace std;

class StatisticsScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(vector<int> n_c, vector<int> n_ic);
    
    virtual bool init(vector<int> n_corr, vector<int> n_incorr);
    
    // a selector callback
    void back_callback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    static StatisticsScene* create(vector<int> num_correct, vector<int> num_incorrect)
    {
        StatisticsScene *pRet = new(std::nothrow) StatisticsScene();
        if (pRet && pRet->init(num_correct, num_incorrect))
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

};

#endif /* StatisticsScene_hpp */
