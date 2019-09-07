//
//  entity.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 04/03/17.
//
//

#ifndef entity_hpp
#define entity_hpp

#include "cocos2d.h"
#include <stdio.h>

using namespace std;
using namespace cocos2d;

class entity{
public:
    
    Sprite *sprite;
    bool is_biodegradable;
    string hint_audio_path_english;
    string hint_audio_path_hindi;
    
    bool operator == (const entity& e) const {
        return (sprite==e.sprite && is_biodegradable==e.is_biodegradable && hint_audio_path_english==e.hint_audio_path_english && hint_audio_path_hindi==e.hint_audio_path_hindi);
    }
    
    //entity(Sprite *spr, bool is_bio, string e_path, string h_path);
};


#endif /* entity_hpp */
