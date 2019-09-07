//
//  ParticleLayer.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 22/01/17.
//
//

#ifndef ParticleLayer_hpp
#define ParticleLayer_hpp

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

class ParticleLayer : public cocos2d::Layer
{
private:
    ParticleExplosion *particle;
    
public:
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(ParticleLayer);
    
    
    void show_particles();
    void hide_particles(float dt);
};


#endif /* ParticleLayer_hpp */
