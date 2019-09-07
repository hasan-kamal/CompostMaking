//
//  Level.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#ifndef Level_hpp
#define Level_hpp

#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
using namespace std;

struct obj{
    string image_path;
    string hint_sound_path_english;
    string hint_sound_path_hindi;
    bool is_biodegradable;
    int level_number;
};

class Level{
public:
    //static const vector<pair<vector<string>, vector<string> > > images;
    static const vector<obj> objects;
    static const int max_level_number;
};

#endif /* Level_hpp */
