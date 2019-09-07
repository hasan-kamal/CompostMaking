//
//  LevelCompost.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#ifndef LevelCompost_hpp
#define LevelCompost_hpp

#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
using namespace std;

struct objCompost{
    string image_path;
    string hint_sound_path_english;
    string hint_sound_path_hindi;
    bool can_be_put_in_compost;
    int level_number;
};

class LevelCompost{
public:
    //static const vector<pair<vector<string>, vector<string> > > images;
    static const vector<objCompost> objects;
    static const int max_level_number;
};

#endif /* LevelCompost_hpp */
