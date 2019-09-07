//
//  ParticleLayer.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#include "ParticleLayer.hpp"
using namespace cocos2d;

bool ParticleLayer::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //fireworks
    particle = ParticleExplosion::createWithTotalParticles(50);
    particle->setPosition(origin+visibleSize/2);
    particle->setVisible(false);
    this->addChild(particle);
    
    return true;
}


void ParticleLayer::show_particles(){
    particle->resetSystem();
    particle->setVisible(true);
    this->schedule(schedule_selector(ParticleLayer::hide_particles), 4.0f);
}

void ParticleLayer::hide_particles(float dt){
    this->unschedule(schedule_selector(ParticleLayer::hide_particles));
    
    particle->stopSystem();
    particle->setVisible(false);
}
