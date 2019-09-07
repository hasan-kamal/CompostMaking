//
//  GlobalSettings.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#include "GlobalSettings.hpp"

const bool GlobalSettings::soundOn = true;
const int GlobalSettings::inactivity_time_max = 10;

const int GlobalSettings::max_balloon_pops = 10;
const int GlobalSettings::max_fireworks = 5;
const int GlobalSettings::max_num_wrong_attempt = 6;

//following are editable via settings scene
bool GlobalSettings::language_preference_english = true;
bool GlobalSettings::hint_enable = true;
bool GlobalSettings::feedback_enable = true;

const string GlobalSettings::balloon_pop = "sounds/balloon_pop.mp3";
const string GlobalSettings::click = "sounds/click.mp3";
const string GlobalSettings::correct_answer = "sounds/correct_answer.mp3";
const string GlobalSettings::metal_clang = "sounds/metal_clang.mp3";
const string GlobalSettings::wrong_answer = "sounds/wrong_answer.mp3";
const string GlobalSettings::prompt = "sounds/come_back_funny.mp3";
const string GlobalSettings::prompt_hindi = "sounds/waapis_ao_funny.mp3";
const string GlobalSettings::explosion = "sounds/explosion.mp3";
