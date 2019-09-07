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
#include "TextFieldInputLayer.hpp"

class StartScene : public cocos2d::Layer
{
private:
    TextFieldInputLayer *textFieldInputLayer;
    bool bio_mode = false;
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void settings_callback(cocos2d::Ref* pSender);
    void db_callback(cocos2d::Ref* pSender);
    void play_compost_callback(cocos2d::Ref* pSender);
    void play_bio_callback(cocos2d::Ref* pSender);
    void start(string student_name);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};


#endif /* StartScene_hpp */
