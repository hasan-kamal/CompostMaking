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

class Level{
public:
    static const vector<pair<vector<string>, vector<string> > > images;
    static const int max_level_number;
};

#endif /* Level_hpp */
