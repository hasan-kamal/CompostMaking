//
//  GlobalSettings.hpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#ifndef GlobalSettings_hpp
#define GlobalSettings_hpp

#include <stdio.h>
#include <string>
using namespace std;

class GlobalSettings{
public:
    const static int inactivity_time_max; //in seconds
    const static bool soundOn;
    const static int max_balloon_pops;
    const static int max_fireworks;
    const static int max_num_wrong_attempt;
    
    static bool language_preference_english;
    static bool hint_enable;
    static bool feedback_enable;
    
    //audio file names/paths
    const static string balloon_pop;
    const static string click;
    const static string correct_answer;
    const static string metal_clang;
    const static string wrong_answer;
    const static string prompt;
    const static string prompt_hindi;
    const static string explosion;
};

#endif /* GlobalSettings_hpp */
