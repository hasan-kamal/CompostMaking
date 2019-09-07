//
//  GameScene.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#include "GameScene.hpp"
#include "Colors.hpp"
#include "StartScene.hpp"
#include "Level.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "GlobalSettings.hpp"
#include "RewardSelectionScene.hpp"
#include "SimpleAudioEngine.h"
#include <math.h>
#include "StatisticsScene.hpp"
#include "Statistics.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;


void GameScene::onExit(){
    Layer::onExit();
}

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameScene::is_vector_within_sprite(Sprite *s, Vec2 vector){
    if(s==nullptr)
        return false;
    
    double x1 = s->getPosition().x - s->getContentSize().width*s->getScale()/2;
    double x2 = s->getPosition().x + s->getContentSize().width*s->getScale()/2;
    double y1 = s->getPosition().y - s->getContentSize().height*s->getScale()/2;
    double y2 = s->getPosition().y + s->getContentSize().height*s->getScale()/2;
    
    if(vector.x>x1 && vector.x<x2 && vector.y>y1 && vector.y<y2)
        return true;
    
    return false;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //background
    auto background = DrawNode::create();
    background->drawSolidRect(origin, Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height), Colors::white);
    this->addChild(background);
    
    //background_sprite
    auto background_sprite = Sprite::create("background.png");
    float scale = visibleSize.height/background_sprite->getContentSize().height;
    if(visibleSize.width/background_sprite->getContentSize().width>scale)
        scale = visibleSize.width/background_sprite->getContentSize().width;
    background_sprite->setScale(scale);
    background_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    background_sprite->setPosition(origin + visibleSize/2.0);
    background_sprite->setOpacity(100);
    this->addChild(background_sprite);
    
    //particle_layer
    particle_layer = ParticleLayer::create();
    this->addChild(particle_layer);
    
    //closeItem
    auto closeItem = MenuItemImage::create(
                                           "left_angle.png",
                                           "left_angle.png",
                                           CC_CALLBACK_1(GameScene::back_clicked, this));
    closeItem->setScale(visibleSize.height*6.0/100.0/closeItem->getContentSize().height);
    closeItem->setAnchorPoint(Vec2(1.0, 0.0));
    float padding = visibleSize.height*2.0/100.0;
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - padding ,
                                origin.y + padding));
	
	
	//balloonItem
	auto balloonItem = MenuItemImage::create(
                                           "balloon_icon_scaled.png",
                                           "balloon_icon_scaled.png",
                                           CC_CALLBACK_1(GameScene::start_reward, this));
    balloonItem->setScale(visibleSize.height*8.0/100.0/balloonItem->getContentSize().height);
    balloonItem->setAnchorPoint(Vec2(0.0, 0.0));
    balloonItem->setPosition(Vec2(origin.x + padding ,
                                origin.y + padding));
    
    //menu_level_selection
    auto menu_level_selection = MenuItemImage::create("menu_button.png", "menu_button.png", CC_CALLBACK_1(GameScene::menu_level_select, this));
    menu_level_selection->setScale(visibleSize.height*5.0/100.0/menu_level_selection->getContentSize().height);
    menu_level_selection->setAnchorPoint(Vec2(1.0, 1.0));
    menu_level_selection->setPosition(Vec2(origin.x + visibleSize.width - padding, origin.y + visibleSize.height - padding));
    
    auto menu = Menu::create(closeItem, balloonItem, menu_level_selection, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //green tray
    green_tray = Sprite::create("green_tray_bright.png");
    green_tray->setScale(visibleSize.height*35.0/100.0/green_tray->getContentSize().height);
    green_tray->setAnchorPoint(Vec2(0.5, 0.5));
    float paddingBetween = visibleSize.width*5.0/100;
    float width = green_tray->getContentSize().width*green_tray->getScale();
    green_tray->setPosition(Vec2(origin.x + visibleSize.width/2 - paddingBetween - width/2, origin.y + visibleSize.height*35.0/100));
    this->addChild(green_tray);
    cout<<"green.x "<<green_tray->getPosition().x<<" green.y "<<green_tray->getPosition().y<<endl;
    
    //blue tray
    blue_tray = Sprite::create("blue_tray.png");
    blue_tray->setScale(visibleSize.height*35.0/100.0/blue_tray->getContentSize().height);
    blue_tray->setAnchorPoint(Vec2(0.5, 0.5));
    blue_tray->setPosition(Vec2(origin.x + visibleSize.width/2 + paddingBetween + width/2, origin.y + visibleSize.height*35.0/100));
    this->addChild(blue_tray);
    cout<<"blue.x "<<blue_tray->getPosition().x<<" blue.y "<<blue_tray->getPosition().y<<endl;
    
    //touch listener
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchEventListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    touchEventListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    //current_level_number
    current_level_number = Label::createWithTTF("#1", "fonts/Trirong-Light.ttf", 25);
    current_level_number->setAnchorPoint(Vec2(1.0, 1.0));
    current_level_number->setPosition(Vec2(origin.x + visibleSize.width*90.0/100.0, origin.y + visibleSize.height*94.0/100.0));
    current_level_number->setColor(Color3B(Colors::wet_asphalt));
    this->addChild(current_level_number, 1);
    
    //border_sprite
    border_sprite = Sprite::create("peter_river.png");
    border_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    this->addChild(border_sprite);
    
    auto fadeOut = FadeTo::create(0.5f, 100);
    auto fadeIn = FadeTo::create(0.5f, 255);
    auto seq = Sequence::create(fadeOut, fadeIn, NULL);
    auto repeatSeq = RepeatForever::create(seq);
    border_sprite->runAction(repeatSeq);
    
    //initialize sprites
    //for(string s : Level::images.at(0).first){
    for(obj o : Level::objects){
        if(o.level_number==1){
            string s = o.image_path;
            auto sprite = Sprite::create(s);
            
            entity e{sprite, o.is_biodegradable, o.hint_sound_path_english, o.hint_sound_path_hindi};
            objects_unanswered.push_back(e);
            
            this->addChild(sprite);
            sprite->setVisible(false);
        }
    }
    
    shuffle_unanswered_objects();
    
    for(int i=0; i<objects_unanswered.size()+objects_correct.size(); i++){
        auto full_sprite = Sprite::create("star.png");
        full_sprite->setScale(visibleSize.height*6.5/100/full_sprite->getContentSize().height);
        full_sprite->setVisible(false);
        
        auto fadeOut = FadeTo::create(0.5f, 100);
        auto fadeIn = FadeTo::create(0.5f, 255);
        auto seq = Sequence::create(fadeOut, fadeIn, NULL);
        auto repeatSeq = RepeatForever::create(seq);
        repeatSeq->setTag(100);
        full_sprite->runAction(repeatSeq);
        
        this->addChild(full_sprite);
        
        auto empty_sprite = Sprite::create("star_empty.png");
        empty_sprite->setScale(visibleSize.height*4.0/100/empty_sprite->getContentSize().height);
        //empty_sprite->setOpacity(200);
        empty_sprite->setVisible(false);
        this->addChild(empty_sprite);
        
        star_sprites.push_back(pair<Sprite *, Sprite *>(full_sprite, empty_sprite));
    }
    
    restart_level();
    
    visual_layer = VisualLayer::create();
    this->addChild(visual_layer, 1);
    
    //label_level
    label_level = Label::createWithTTF("Level", "fonts/Trirong-Light.ttf", 25);
    label_level->setPosition(origin+visibleSize/2);
    label_level->setColor(Color3B(Colors::concrete));
    label_level->enableOutline(Color4B(Colors::clouds));
    label_level->enableGlow(Color4B(Colors::clouds));
    label_level->setOpacity(0);
    this->addChild(label_level, 1);
    
    //character_layer
    character_layer = CharacterLayer::create();
    this->addChild(character_layer);
    
    //schedule update to be able to measure
    //elapsed time for determining inactivity
    scheduleUpdate();
	
	//bottom border
	auto bottom_border = Sprite::create("tapered_line.png");
	bottom_border->setScale(visibleSize.width*85.0/100.0/bottom_border->getContentSize().width, visibleSize.height*2.5/100.0/bottom_border->getContentSize().height);
	bottom_border->setOpacity(100);
    bottom_border->setAnchorPoint(Vec2(0.5, 0.5));
    bottom_border->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height*5.0/100));
    this->addChild(bottom_border);
	
	
	//top border
	auto top_border = Sprite::create("tapered_line.png");
	top_border->setScale(visibleSize.width*85.0/100.0/top_border->getContentSize().width, visibleSize.height*2.5/100.0/top_border->getContentSize().height);
	top_border->setOpacity(100);
    top_border->setAnchorPoint(Vec2(0.5, 0.5));
    top_border->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height*95.0/100));
    this->addChild(top_border);

	
	//left border
	auto left_border = Sprite::create("tapered_line_vertical.png");
    left_border->setScale(visibleSize.height*2.5/100.0/left_border->getContentSize().width, visibleSize.height*90.0/100.0/left_border->getContentSize().height);
	left_border->setOpacity(100);
    left_border->setAnchorPoint(Vec2(0.5, 0.5));
    left_border->setPosition(Vec2(origin.x + visibleSize.width*7.5/100.0 , origin.y + visibleSize.height*50.0/100.0));
    this->addChild(left_border);
	
	//right border
	auto right_border = Sprite::create("tapered_line_vertical.png");
	right_border->setScale(visibleSize.height*2.5/100.0/right_border->getContentSize().width, visibleSize.height*90.0/100.0/right_border->getContentSize().height);
	right_border->setOpacity(100);
    right_border->setAnchorPoint(Vec2(0.5, 0.5));
    right_border->setPosition(Vec2(origin.x + visibleSize.width*92.5/100.0 , origin.y + visibleSize.height*50.0/100));
    this->addChild(right_border);
    
    //LevelSelectionLayer
    level_selection_layer = LevelSelectionLayer::create(this);
    this->addChild(level_selection_layer, 5);
    
    num_correct_attempts = vector<int>(Level::max_level_number, 0);
    num_incorrect_attempts = vector<int>(Level::max_level_number, 0);
    
    return true;
}

void GameScene::update(float dt){
    time_elapsed_last_touch+=dt;
    if(time_elapsed_last_touch>GlobalSettings::inactivity_time_max){
        character_layer->show_prompt();
        time_elapsed_last_touch = 0.0;
    }
}

//touch event callbacks
bool GameScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    if(current_display_object.sprite==nullptr || current_display_object.sprite->isVisible()==false)
        return true;
    
    if(is_vector_within_sprite(current_display_object.sprite, touch->getLocation())){
        touched_sprite_initially = true;
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
        position_at_time_touch = current_display_object.sprite->getPosition();
    }
    
    time_elapsed_last_touch = 0.0;
    
    return true;
}

void GameScene::onTouchMoved(Touch *touch, Event *unused_event){
    if(!touched_sprite_initially)
        return;
    
    current_display_object.sprite->setPosition(position_at_time_touch + touch->getLocation()-touch->getStartLocation());
    
    Vec2 min_vec;
    min_vec = current_display_object.sprite->getPosition() - green_tray->getPosition();
    if(min_vec.length()>(current_display_object.sprite->getPosition() - blue_tray->getPosition()).length())
        min_vec = current_display_object.sprite->getPosition() - blue_tray->getPosition();
        
    current_display_object.sprite->setScale(fmax( green_tray->getContentSize().height*10/100/current_display_object.sprite->getContentSize().height, original_sprite_scale*(min_vec.length()/tray_to_sprite_intial.length()) ));
    
    sprite_border_reposition();
    
    time_elapsed_last_touch = 0.0;
}

void GameScene::sprite_border_reposition(){
    border_sprite->setPosition(current_display_object.sprite->getPosition());
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float border_width = visibleSize.height*1.0/100;
    border_sprite->setScale( (current_display_object.sprite->getContentSize().width*current_display_object.sprite->getScale() + border_width)/border_sprite->getContentSize().width, (current_display_object.sprite->getContentSize().height*current_display_object.sprite->getScale() + border_width)/border_sprite->getContentSize().height );
}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    if(!touched_sprite_initially)
        return;
    
    if(is_vector_within_sprite(green_tray, touch->getLocation())){
        
        if(current_display_object.is_biodegradable)
            correct_answer();
        else{
			wrong_answer();
			sprite_reposition();
		}
        
    }else if(is_vector_within_sprite(blue_tray, touch->getLocation())){
        
        if(!current_display_object.is_biodegradable)
            correct_answer();
        else{
			wrong_answer();
			sprite_reposition();
		}
        
    }else{
		sprite_reposition();
    }

    time_elapsed_last_touch = 0.0;
}

void  GameScene::sprite_reposition(){
	auto action_move_back = MoveTo::create(0.5f, position_at_time_touch);
	auto ease_move = EaseBackOut::create(action_move_back);
	current_display_object.sprite->runAction(ease_move);
    
    border_sprite->runAction(ease_move->clone());
	
    touched_sprite_initially = false;
	
    auto scale_back = ScaleTo::create(0.5f, original_sprite_scale);
	current_display_object.sprite->runAction(scale_back);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float border_width = visibleSize.height*1.0/100;
    float sx = (current_display_object.sprite->getContentSize().width*original_sprite_scale + border_width)/border_sprite->getContentSize().width;
    float sy = (current_display_object.sprite->getContentSize().height*original_sprite_scale + border_width)/border_sprite->getContentSize().height;
    auto scale_border_back = ScaleTo::create(0.5f, sx, sy);
    border_sprite->runAction(scale_border_back);
}

void GameScene::correct_answer(){
    num_correct_attempts[level_number]++;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
    if(GlobalSettings::feedback_enable){
        CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
        if(GlobalSettings::language_preference_english)
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(current_display_object.hint_audio_path_english.c_str());
        else
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(current_display_object.hint_audio_path_hindi.c_str());
    }else{
        CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.1);
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::correct_answer.c_str());
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::metal_clang.c_str());
    }
    
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //move and scale down
    current_display_object.sprite->setAnchorPoint(Vec2(0.5, 0.5));
    auto destination_pos = current_display_object.is_biodegradable?green_tray->getPosition():blue_tray->getPosition();
    auto action_move_to = MoveTo::create(0.3f, destination_pos);
    auto ease_move = EaseIn::create(action_move_to, 5.0f);
    auto scale_down = ScaleTo::create(0.3f, green_tray->getContentSize().height*8/100/current_display_object.sprite->getContentSize().height);
    current_display_object.sprite->runAction(ease_move);
    current_display_object.sprite->runAction(scale_down);
    
    //remove current_object from objects_unanswered
    cout<<"Size before removal: "<<objects_unanswered.size()<<endl;
    vector<entity>::iterator pos = std::find(objects_unanswered.begin(), objects_unanswered.end(), current_display_object);
    if(pos!=objects_unanswered.end())
        objects_unanswered.erase(pos);
    cout<<"Size after removal: "<<objects_unanswered.size()<<endl;
    
    //add current_display_object to objects_correct
    objects_correct.push_back(current_display_object);
    
    //set new current_display_object
    if(objects_unanswered.size()>0)
        set_object_display(objects_unanswered.at(0));
    else{
        next_level();
    }
    
    update_stars();
    
    visual_layer->show_happy_face();
    character_layer->show_happy_jump();
    
    num_consecutive_wrong = 0;
    
}

void GameScene::wrong_answer(){
    num_incorrect_attempts[level_number]++;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
    if(GlobalSettings::hint_enable){
        CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
        if(GlobalSettings::language_preference_english)
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(current_display_object.hint_audio_path_english.c_str());
        else
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(current_display_object.hint_audio_path_hindi.c_str());
    }else{
        CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.1);
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::wrong_answer.c_str());
    }
    
//    auto action_move_back = MoveTo::create(0.5f, position_at_time_touch);
//    auto ease_move = EaseBackOut::create(action_move_back);
//    current_display_object.first->runAction(ease_move);
//    touched_sprite_initially = false;
//    
//    auto scale_back = ScaleTo::create(0.5f, original_sprite_scale);
//    current_display_object.first->runAction(scale_back);
    num_consecutive_wrong++;
    if(num_consecutive_wrong>GlobalSettings::max_num_wrong_attempt && int(objects_unanswered.size())>1){
        
        current_display_object.sprite->setVisible(false);
        
        //pick another random object from ones which are still unanswered
        shuffle_unanswered_objects();
        entity lhs = objects_unanswered.at(0);
        entity rhs = current_display_object;
        if(lhs==rhs){
            cout<<"outta luck"<<endl<<endl;
            //swap 0th and 1st object, otherwise we'll be switching to the same object
            entity temp = objects_unanswered.at(0);
            objects_unanswered.at(0) = objects_unanswered.at(1);
            objects_unanswered.at(1) = temp;
        }
        
        //set the first(0th) element of objects_unanswered to current_display_object
        set_object_display(objects_unanswered.at(0));
        
        num_consecutive_wrong = 0;
    }
    
    visual_layer->show_sad_face();
    character_layer->show_sad_expression();
    
    //restart_level();
}

void GameScene::set_object_display(entity obj_to_disp){
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto sprite = obj_to_disp.sprite;
    sprite->setScale(visibleSize.height*32/100/sprite->getContentSize().height);
    original_sprite_scale = visibleSize.height*32/100/sprite->getContentSize().height;
    sprite->setAnchorPoint(Vec2(0.5, 0.5));
    sprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*70/100));
    sprite->setVisible(true);
    
    current_display_object = obj_to_disp;
    tray_to_sprite_intial = sprite->getPosition() - green_tray->getPosition();
    
    sprite_border_reposition();
}

void GameScene::next_level(){
    
    cout<<"next_level"<<endl;
    switch_level(level_number+1);
    
    particle_layer->show_particles();
    if(level_number!=0){
        auto reward_scene = RewardSelectionScene::createScene();
        Director::getInstance()->pushScene(TransitionFade::create(0.5f, reward_scene, Color3B(Colors::clouds)));
    }else{
        Statistics::save_stat(num_correct_attempts, num_incorrect_attempts);
        
        auto statistics_scene = StatisticsScene::createScene(num_correct_attempts, num_incorrect_attempts);
        Director::getInstance()->pushScene(TransitionFade::create(0.5f, statistics_scene, Color3B(Colors::clouds)));
        
        num_correct_attempts = vector<int>(Level::max_level_number, 0);
        num_incorrect_attempts = vector<int>(Level::max_level_number, 0);
    }
}


void GameScene::switch_level(int new_level_index){
    
    cout<<"switching to level number "<<new_level_index+1<<endl;
    
    //free up old resources
    for(auto o : objects_unanswered)
        this->removeChild(o.sprite);
    
    for(auto o : objects_correct)
        this->removeChild(o.sprite);
    
    for(auto s : star_sprites){
        this->removeChild(s.first);
        this->removeChild(s.second);
    }
    
    objects_unanswered.clear();
    objects_correct.clear();
    star_sprites.clear();
    current_display_object.sprite = nullptr;

    //remove this simply, if causing problems
    //free textures (bring down memory footprint)
    Director::getInstance()->purgeCachedData();
    
    //update level number
    level_number = new_level_index;
    level_number = level_number%Level::max_level_number;
    
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    char str[50];
    sprintf(str, "Level %d", level_number+1);
    label_level->setString(str);
    label_level->setOpacity(255);
    auto fade_out = FadeOut::create(2.0);
    label_level->runAction(fade_out);
    
    char str2[50];
    sprintf(str2, "#%d", level_number+1);
    current_level_number->setString(str2);
    
    //load new level resources
    //for(string s : Level::images.at(level_number).first){
    for(obj o : Level::objects){
        if(o.level_number==level_number+1){
            string s = o.image_path;
            auto sprite = Sprite::create(s);
            
            entity e{sprite, o.is_biodegradable, o.hint_sound_path_english, o.hint_sound_path_hindi};
            objects_unanswered.push_back(e);
            
            this->addChild(sprite);
            sprite->setVisible(false);
        }
    }
    
    shuffle_unanswered_objects();
    
    for(int i=0; i<objects_unanswered.size()+objects_correct.size(); i++){
        auto full_sprite = Sprite::create("star.png");
        full_sprite->setScale(visibleSize.height*6.5/100/full_sprite->getContentSize().height);
        full_sprite->setVisible(false);
        this->addChild(full_sprite);
        
        auto fadeOut = FadeTo::create(0.5f, 100);
        auto fadeIn = FadeTo::create(0.5f, 255);
        auto seq = Sequence::create(fadeOut, fadeIn, NULL);
        auto repeatSeq = RepeatForever::create(seq);
        repeatSeq->setTag(100);
        full_sprite->runAction(repeatSeq);
        
        auto empty_sprite = Sprite::create("star_empty.png");
        empty_sprite->setScale(visibleSize.height*4.0/100/empty_sprite->getContentSize().height);
        //empty_sprite->setOpacity(200);
        empty_sprite->setVisible(false);
        this->addChild(empty_sprite);
        
        star_sprites.push_back(pair<Sprite *, Sprite *>(full_sprite, empty_sprite));
    }
    
    
    restart_level();
}

void GameScene::restart_level(){
    //make all objects unanswered
    for(auto s : objects_correct)
        objects_unanswered.push_back(s);
    shuffle_unanswered_objects();
    
    //no correct answer yet
    objects_correct.clear();
    
    //set all objects out of visible area
    for(auto s : objects_unanswered){
        s.sprite->setAnchorPoint(Vec2(1, 1));
        s.sprite->setPosition(Director::getInstance()->getVisibleOrigin());
    }
    
    //make only one object visible now
    set_object_display(objects_unanswered.at(0));
    
    update_stars();
    
//    for(auto l : labels_for_levels)
//        l->setTextColor(Color4B(Colors::asbestos));
//    labels_for_levels.at(level_number)->setTextColor(Color4B(Colors::alizarin));
}

void GameScene::update_stars(){
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    float empty_space = visibleSize.width*5/100;
    cout<<star_sprites.size()<<" is the star's size"<<endl;
    for(int i=1; i<=star_sprites.size(); i++){
        auto star = star_sprites.at(i-1);
        
        Sprite *sprite_chosen;
        
        if(i<=objects_correct.size()){
            star.first->setVisible(true);
            sprite_chosen = star.first;
            star.second->setVisible(false);
        }else{
            star.second->setVisible(true);
            sprite_chosen = star.second;
            star.first->setVisible(false);
        }
        
        sprite_chosen->setAnchorPoint(Vec2(0.5, 0.0));
        
        float bottomPadding = visibleSize.height*9.0/100;
        if(star_sprites.size()%2==1){
            if(i<=(star_sprites.size()+1)/2)
                sprite_chosen->setPosition(Vec2(origin.x + visibleSize.width/2 - ((star_sprites.size()+1)/2-i)*empty_space, origin.y + bottomPadding));
            else
                sprite_chosen->setPosition(Vec2(origin.x + visibleSize.width/2 + (i-(star_sprites.size()+1)/2)*empty_space, origin.y + bottomPadding));
        }else
            sprite_chosen->setPosition(Vec2(origin.x + visibleSize.width/2 - ((star_sprites.size()+1)/2.0-i)*empty_space, origin.y + bottomPadding));
        
    }
}

void GameScene::back_clicked(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    auto startScene = StartScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, startScene, Color3B(Colors::clouds)));
}

void GameScene::start_reward(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
	auto reward_scene = RewardSelectionScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.5f, reward_scene, Color3B(Colors::clouds)));
}

void GameScene::menu_level_select(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(GlobalSettings::click.c_str());
    level_selection_layer->show();
}

void GameScene::shuffle_unanswered_objects(){
    random_shuffle(objects_unanswered.begin(), objects_unanswered.end());
}
