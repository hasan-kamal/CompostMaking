//
//  Level.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#include "Level.hpp"

//const vector<pair<vector<string>, vector<string> > > Level::images{
//    
//    pair<vector<string>, vector<string> >({"Level1/coriander_leaves.png", "Level1/dry_leaf.png", "Level1/peas_pod.png", "Level1/potato_peel.png"}, {"Level1/transparent_cup.png", "Level1/transparent_plastic_bag_2.png", "Level1/transparent_plastic_bag.png", "Level1/transparent_plastic_bottle_2.png", "Level1/transparent_plastic_bottle.png", "Level1/transparent_plastic_container_2.png", "Level1/transparent_plastic_container.png"}),
//    
//    pair<vector<string>, vector<string> >({"Level2/carrot_peel_2.jpg", "Level2/carrot_peel.jpg", "Level2/potato_peel_2.jpg", "Level2/potato_peel_3.jpg"}, {"Level2/coke_bottle.jpg", "Level2/colored_plastic_bag.jpg", "Level2/colored_plastic_bottle_2.jpg", "Level2/colored_plastic_bottle_3.jpg", "Level2/dettol_bottle.jpg", "Level2/colored_plastic_container_2.jpg", "Level2/colored_plastic_containers.jpg"}),
//    
//    pair<vector<string>, vector<string> >({"Level3/banana_peel.jpg", "Level3/bread.jpg", "Level3/cucumber_peel.jpg", "Level3/egg-shell.jpg", "Level3/rice.jpg"}, {"Level3/chips_packet_2.jpg", "Level3/empty_candy_wrapper.jpg", "Level3/chips_packet.jpg", "Level3/snickers_wrapper.jpg", "Level3/toffee_wrapper.jpg", "Level3/wrappers.jpg"}),
//    
//    pair<vector<string>, vector<string> >({"Level4/biscuit.jpg", "Level4/onion.jpg", "Level4/roti.png", "Level4/watermelon.jpg"}, {"Level4/bolt.jpg", "Level4/keys.jpg", "Level4/metal_bolt.jpg", "Level4/metallic_nut.jpg", "Level4/nut.jpg", "Level4/pin.jpg", "Level4/spoon.jpg"}),
//    
//    pair<vector<string>, vector<string> >({"Level5/apple_waste.jpg", "Level5/leaf.jpg", "Level5/pear_peel.png"}, {"Level5/lemon_waste.jpg", "Level5/lemon_waste_2.jpg", "Level5/plastic_bottle_cap.jpg", "Level5/seeds.jpg", "Level5/seeds_2.jpg"})
//    
//};

/*
 
 struct obj{
 string image_path;
 string hint_sound_path;
 bool is_biodegradable;
 int level_number;
 };
 
 */
const vector<obj> Level::objects{
    
    //Level1
    {"Imagesv4_bio/Level1/coriander_leaves.png", "hint_soundsv4_bio/level1/coriander.m4a", "hint_soundsv4_bio/hindi/level1/coriander.mp3", true, 1},
    {"Imagesv4_bio/Level1/dry_leaf.png", "hint_soundsv4_bio/level1/leaf.m4a", "hint_soundsv4_bio/hindi/level1/leaf.mp3", true, 1},
    {"Imagesv4_bio/Level1/peas_pod.png", "hint_soundsv4_bio/level1/pea.m4a", "hint_soundsv4_bio/hindi/level1/pea.mp3", true, 1},
    {"Imagesv4_bio/Level1/potato_peel.png", "hint_soundsv4_bio/level1/potato.m4a", "hint_soundsv4_bio/hindi/level1/potato.mp3", true, 1},
    
    {"Imagesv4_bio/Level1/transparent_cup.png", "hint_soundsv4_bio/level1/cup.m4a", "hint_soundsv4_bio/hindi/level1/cup.mp3",false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_bag_2.png", "hint_soundsv4_bio/level1/bag.m4a", "hint_soundsv4_bio/hindi/level1/polythene.mp3", false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_bag.png", "hint_soundsv4_bio/level1/bag.m4a", "hint_soundsv4_bio/hindi/level1/polythene.mp3", false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_bottle_2.png", "hint_soundsv4_bio/level1/bottle.m4a", "hint_soundsv4_bio/hindi/level1/bottle.mp3", false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_bottle.png", "hint_soundsv4_bio/level1/bottle.m4a", "hint_soundsv4_bio/hindi/level1/bottle.mp3", false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_container_2.png", "hint_soundsv4_bio/level1/container.m4a", "hint_soundsv4_bio/hindi/level1/container.mp3", false, 1},
    {"Imagesv4_bio/Level1/transparent_plastic_container.png", "hint_soundsv4_bio/level1/container.m4a", "hint_soundsv4_bio/hindi/level1/container.mp3", false, 1},
    
    //Level2
    {"Imagesv4_bio/Level2/carrot_peel_2.jpg", "hint_soundsv4_bio/level2/carrot.m4a", "hint_soundsv4_bio/hindi/level2/carrot.mp3", true, 2},
    {"Imagesv4_bio/Level2/carrot_peel.jpg", "hint_soundsv4_bio/level2/carrot.m4a", "hint_soundsv4_bio/hindi/level2/carrot.mp3", true, 2},
    {"Imagesv4_bio/Level2/potato_peel_2.jpg", "hint_soundsv4_bio/level2/potato.m4a", "hint_soundsv4_bio/hindi/level2/potato.mp3", true, 2},
    {"Imagesv4_bio/Level2/potato_peel_3.jpg", "hint_soundsv4_bio/level2/potato.m4a", "hint_soundsv4_bio/hindi/level2/potato.mp3", true, 2},
    
    {"Imagesv4_bio/Level2/coke_bottle.jpg", "hint_soundsv4_bio/level2/coke_bottle.m4a", "hint_soundsv4_bio/hindi/level2/bottle.mp3", false, 2},
    {"Imagesv4_bio/Level2/colored_plastic_bag.jpg", "hint_soundsv4_bio/level2/bag.m4a", "hint_soundsv4_bio/hindi/level2/polythene.mp3", false, 2},
    {"Imagesv4_bio/Level2/colored_plastic_bottle_2.jpg", "hint_soundsv4_bio/level2/bottle.m4a", "hint_soundsv4_bio/hindi/level2/bottle.mp3", false, 2},
    {"Imagesv4_bio/Level2/colored_plastic_bottle_3.jpg", "hint_soundsv4_bio/level2/bottle.m4a", "hint_soundsv4_bio/hindi/level2/bottle.mp3", false, 2},
    {"Imagesv4_bio/Level2/colored_plastic_container_2.jpg", "hint_soundsv4_bio/level2/container.m4a", "hint_soundsv4_bio/hindi/level2/container.mp3", false, 2},
    {"Imagesv4_bio/Level2/colored_plastic_containers.jpg", "hint_soundsv4_bio/level2/container.m4a", "hint_soundsv4_bio/hindi/level2/container.mp3", false, 2},
    
    //Level3
    {"Imagesv4_bio/Level3/banana_peel.jpg", "hint_soundsv4_bio/level3/banana.m4a", "hint_soundsv4_bio/hindi/level3/banana.mp3", true, 3},
    {"Imagesv4_bio/Level3/bread.jpg", "hint_soundsv4_bio/level3/bread.m4a", "hint_soundsv4_bio/hindi/level3/roti.mp3", true, 3},
    {"Imagesv4_bio/Level3/cucumber_peel.jpg", "hint_soundsv4_bio/level3/cucumber.m4a", "hint_soundsv4_bio/hindi/level3/cucumber.mp3", true, 3},
    {"Imagesv4_bio/Level3/egg-shell.jpg", "hint_soundsv4_bio/level3/egg_shell.m4a", "hint_soundsv4_bio/hindi/level3/egg.mp3", true, 3},
    {"Imagesv4_bio/Level3/leaf_new_dry.png", "hint_soundsv4_bio/level3/leaf.m4a", "hint_soundsv4_bio/hindi/level3/leaf.mp3", true, 3},

    {"Imagesv4_bio/Level3/chips_packet_2.jpg", "hint_soundsv4_bio/level3/chips_packet.m4a", "hint_soundsv4_bio/hindi/level3/chips.mp3", false, 3},
    {"Imagesv4_bio/Level3/empty_candy_wrapper.jpg", "hint_soundsv4_bio/level3/toffee_wrapper.m4a", "hint_soundsv4_bio/hindi/level3/toffee_packet.mp3", false, 3},
    {"Imagesv4_bio/Level3/chips_packet.jpg", "hint_soundsv4_bio/level3/chips_packet.m4a", "hint_soundsv4_bio/hindi/level3/chips.mp3", false, 3},
    {"Imagesv4_bio/Level3/snickers_wrapper.jpg", "hint_soundsv4_bio/level3/chocolate_wrapper.m4a", "hint_soundsv4_bio/hindi/level3/chocolate_packet.mp3", false, 3},
    {"Imagesv4_bio/Level3/toffee_wrapper.jpg", "hint_soundsv4_bio/level3/toffee_wrapper.m4a", "hint_soundsv4_bio/hindi/level3/toffee_packet.mp3", false, 3},
    {"Imagesv4_bio/Level3/wrappers.jpg", "hint_soundsv4_bio/level3/chocolate_wrapper.m4a", "hint_soundsv4_bio/hindi/level3/chocolate_packet.mp3", false, 3},
    
    //Level4
    {"Imagesv4_bio/Level4/crumpled_paper_balls.jpeg", "hint_soundsv4_bio/level4/paper.m4a", "hint_soundsv4_bio/hindi/level4/paper.mp3", true, 4},
    {"Imagesv4_bio/Level4/onion.jpg", "hint_soundsv4_bio/level4/onion.m4a", "hint_soundsv4_bio/hindi/level4/onion.mp3", true, 4},
    {"Imagesv4_bio/Level4/green_leaf.png", "hint_soundsv4_bio/level4/leaf.m4a", "hint_soundsv4_bio/hindi/level4/leaf.mp3", true, 4},
    {"Imagesv4_bio/Level4/watermelon.jpg", "hint_soundsv4_bio/level4/watermelon.m4a", "hint_soundsv4_bio/hindi/level4/watermelon.mp3", true, 4},
    {"Imagesv4_bio/Level4/Single_Paper_Ball01.jpg5e40e95d-ea37-48ee-a3b2-f457a0dcf76fOriginal.jpg", "hint_soundsv4_bio/level4/paper.m4a", "hint_soundsv4_bio/hindi/level4/paper.mp3", true, 4},
    {"Imagesv4_bio/Level4/vegetable_waste.jpg", "hint_soundsv4_bio/level4/vegetable_waste.m4a", "hint_soundsv4_bio/hindi/level4/vegetable_waste.mp3", true, 4},
    

    {"Imagesv4_bio/Level4/milk_packet.jpg", "hint_soundsv4_bio/level4/milk_packet.m4a", "hint_soundsv4_bio/hindi/level4/milk_packet.mp3", false, 4},
    {"Imagesv4_bio/Level4/milk_packet2.jpg", "hint_soundsv4_bio/level4/milk_packet.m4a", "hint_soundsv4_bio/hindi/level4/milk_packet.mp3", false, 4},
    {"Imagesv4_bio/Level4/plastic_bag_green.jpg", "hint_soundsv4_bio/level4/bag.m4a", "hint_soundsv4_bio/hindi/level4/bag.mp3", false, 4},
    {"Imagesv4_bio/Level4/plastic_bottle_green.jpg", "hint_soundsv4_bio/level4/bottle.m4a", "hint_soundsv4_bio/hindi/level4/bottle.mp3", false, 4},
    
    //Level5
    {"Imagesv4_bio/Level5/apple_waste.jpg", "hint_soundsv4_bio/level5/apple.m4a", "hint_soundsv4_bio/hindi/level5/apple.mp3", true, 5},
    {"Imagesv4_bio/Level5/blue_paper_ball.jpg", "hint_soundsv4_bio/level5/paper.m4a", "hint_soundsv4_bio/hindi/level5/paper.mp3", true, 5},
    {"Imagesv4_bio/Level5/leaf.jpg", "hint_soundsv4_bio/level5/leaf.m4a", "hint_soundsv4_bio/hindi/level5/leaf.mp3", true, 5},
    {"Imagesv4_bio/Level5/pear_peel.png", "hint_soundsv4_bio/level5/pear.m4a", "hint_soundsv4_bio/hindi/level5/pear.mp3", true, 5},
    {"Imagesv4_bio/Level5/paper_bits.jpg", "hint_soundsv4_bio/level5/paper.m4a", "hint_soundsv4_bio/hindi/level5/paper.mp3", true, 5},
    {"Imagesv4_bio/Level5/vegetable_waste2.jpg", "hint_soundsv4_bio/level5/vegetable_waste.m4a", "hint_soundsv4_bio/hindi/level5/vegetable_waste.mp3", true, 5},

    {"Imagesv4_bio/Level5/green_cap.png", "hint_soundsv4_bio/level5/bottle_cap.m4a", "hint_soundsv4_bio/hindi/level5/bottle_cap.mp3", false, 5},
    {"Imagesv4_bio/Level5/plastic_bottle_blue.png", "hint_soundsv4_bio/level5/bottle.m4a", "hint_soundsv4_bio/hindi/level5/bottle.mp3", false, 5},
    {"Imagesv4_bio/Level5/plastic_bottle_cap.jpg", "hint_soundsv4_bio/level5/bottle_cap.m4a", "hint_soundsv4_bio/hindi/level5/bottle_cap.mp3", false, 5}
};

const int Level::max_level_number = 5;
