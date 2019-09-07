//
//  Statistics.hpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#ifndef Statistics_hpp
#define Statistics_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Statistics{
public:
    static string player_name;
    static string filename;
    static bool is_bio;
    static void save_stat(vector<int> num_correct, vector<int> num_incorrect);
    static string get_stat();
};

#endif /* Statistics_hpp */
