//
//  GameScene.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp
#include "Level.hpp"
#include "cocos2d.h"
#include "VisualLayer.hpp"
#include "CharacterLayer.hpp"
#include "ParticleLayer.hpp"
#include <queue>
using namespace std;
using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
private:
    
    vector<pair<Sprite *, bool> > objects_unanswered;
    vector<pair<Sprite *, bool> > objects_correct;
    
    vector<Label *> labels_for_levels;
    vector<pair<Sprite *, Sprite *> > star_sprites;
    
    pair<Sprite *, bool> current_display_object;
    Label *label_level;
    
    Vec2 position_at_time_touch;
    bool touched_sprite_initially;
    Vec2 tray_to_sprite_intial;
    double original_sprite_scale;
    
    Sprite *green_tray, *blue_tray;
    VisualLayer *visual_layer;
    ParticleLayer *particle_layer;
    CharacterLayer *character_layer;
    
    void correct_answer();
    void wrong_answer();
    void next_level();
    void restart_level();
    int level_number = 0;
    
    void set_object_display(pair<Sprite *, bool> obj_to_disp);
    void update_stars();
    
    static bool is_vector_within_sprite(Sprite *sprite, Vec2 vector);
    
    double time_elapsed_last_touch = 0.0;
    
    void shuffle_unanswered_objects();

public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual void onExit();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void back_clicked(cocos2d::Ref *pSender);

    //touch event callbacks
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);

    void update(float dt);
};

#endif /* GameScene_hpp */
