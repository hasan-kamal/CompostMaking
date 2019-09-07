//
//  LevelCompost.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#include "LevelCompost.hpp"

const vector<objCompost> LevelCompost::objects{
    
    //Level1
    {"Imagesv4_compost/Level1/coriander_leaves.png", "hint_soundsv4_compost/level1/coriander.m4a", "hint_soundsv4_compost/hindi/level1/coriander.mp3", true, 1},
    {"Imagesv4_compost/Level1/dry_leaf.png", "hint_soundsv4_compost/level1/leaf.m4a", "hint_soundsv4_compost/hindi/level1/leaves.mp3", true, 1},
    {"Imagesv4_compost/Level1/peas_pod.png", "hint_soundsv4_compost/level1/pea.m4a", "hint_soundsv4_compost/hindi/level1/pea.mp3", true, 1},
    {"Imagesv4_compost/Level1/potato_peel.png", "hint_soundsv4_compost/level1/potato.m4a", "hint_soundsv4_compost/hindi/level1/potato.mp3", true, 1},
    
    {"Imagesv4_compost/Level1/transparent_cup.png", "hint_soundsv4_compost/level1/cup.m4a", "hint_soundsv4_compost/hindi/level1/plastic_cup.mp3",false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_bag_2.png", "hint_soundsv4_compost/level1/bag.m4a", "hint_soundsv4_compost/hindi/level1/plastic_bag.mp3", false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_bag.png", "hint_soundsv4_compost/level1/bag.m4a", "hint_soundsv4_compost/hindi/level1/plastic_bag.mp3", false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_bottle_2.png", "hint_soundsv4_compost/level1/bottle.m4a", "hint_soundsv4_compost/hindi/level1/plastic_bottle.mp3", false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_bottle.png", "hint_soundsv4_compost/level1/bottle.m4a", "hint_soundsv4_compost/hindi/level1/plastic_bottle.mp3", false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_container_2.png", "hint_soundsv4_compost/level1/container.m4a", "hint_soundsv4_compost/hindi/level1/plastic_container.mp3", false, 1},
    {"Imagesv4_compost/Level1/transparent_plastic_container.png", "hint_soundsv4_compost/level1/container.m4a", "hint_soundsv4_compost/hindi/level1/plastic_container.mp3", false, 1},
    
    //Level2
    {"Imagesv4_compost/Level2/carrot_peel_2.jpg", "hint_soundsv4_compost/level2/carrot.m4a", "hint_soundsv4_compost/hindi/level2/carrot.mp3", true, 2},
    {"Imagesv4_compost/Level2/carrot_peel.jpg", "hint_soundsv4_compost/level2/carrot.m4a", "hint_soundsv4_compost/hindi/level2/carrot.mp3", true, 2},
    {"Imagesv4_compost/Level2/potato_peel_2.jpg", "hint_soundsv4_compost/level2/potato.m4a", "hint_soundsv4_compost/hindi/level2/potato.mp3", true, 2},
    {"Imagesv4_compost/Level2/potato_peel_3.jpg", "hint_soundsv4_compost/level2/potato.m4a", "hint_soundsv4_compost/hindi/level2/potato.mp3", true, 2},
    
    {"Imagesv4_compost/Level2/coke_bottle.jpg", "hint_soundsv4_compost/level2/coke_bottle.m4a", "hint_soundsv4_compost/hindi/level2/coke_bottle.mp3", false, 2},
    {"Imagesv4_compost/Level2/colored_plastic_bag.jpg", "hint_soundsv4_compost/level2/bag.m4a", "hint_soundsv4_compost/hindi/level2/plastic_bag.mp3", false, 2},
    {"Imagesv4_compost/Level2/colored_plastic_bottle_2.jpg", "hint_soundsv4_compost/level2/bottle.m4a", "hint_soundsv4_compost/hindi/level2/plastic_bottle.mp3", false, 2},
    {"Imagesv4_compost/Level2/colored_plastic_bottle_3.jpg", "hint_soundsv4_compost/level2/bottle.m4a", "hint_soundsv4_compost/hindi/level2/plastic_bottle.mp3", false, 2},
    {"Imagesv4_compost/Level2/colored_plastic_container_2.jpg", "hint_soundsv4_compost/level2/container.m4a", "hint_soundsv4_compost/hindi/level2/plastic_container.mp3", false, 2},
    {"Imagesv4_compost/Level2/colored_plastic_containers.jpg", "hint_soundsv4_compost/level2/container.m4a", "hint_soundsv4_compost/hindi/level2/plastic_container.mp3", false, 2},
    
    //Level3
    {"Imagesv4_compost/Level3/banana_peel.jpg", "hint_soundsv4_compost/level3/banana.m4a", "hint_soundsv4_compost/hindi/level3/banana.mp3", true, 3},
    {"Imagesv4_compost/Level3/cucumber_peel.jpg", "hint_soundsv4_compost/level3/cucumber.m4a", "hint_soundsv4_compost/hindi/level3/cucumber.mp3", true, 3},
    {"Imagesv4_compost/Level3/egg-shell.jpg", "hint_soundsv4_compost/level3/egg_shell.m4a", "hint_soundsv4_compost/hindi/level3/egg_shell.mp3", true, 3},

    {"Imagesv4_compost/Level3/rice.jpg", "hint_soundsv4_compost/level3/rice.m4a", "hint_soundsv4_compost/hindi/level3/rice.mp3", false, 3},
    {"Imagesv4_compost/Level3/chips_packet_2.jpg", "hint_soundsv4_compost/level3/chips_packet.m4a", "hint_soundsv4_compost/hindi/level3/chips_packet.mp3", false, 3},
    {"Imagesv4_compost/Level3/empty_candy_wrapper.jpg", "hint_soundsv4_compost/level3/toffee_wrapper.m4a", "hint_soundsv4_compost/hindi/level3/toffee_packet.mp3", false, 3},
    {"Imagesv4_compost/Level3/chips_packet.jpg", "hint_soundsv4_compost/level3/chips_packet.m4a", "hint_soundsv4_compost/hindi/level3/chips_packet.mp3", false, 3},
    {"Imagesv4_compost/Level3/ice_cream_packet.png", "hint_soundsv4_compost/level3/ice_cream_packet.m4a", "hint_soundsv4_compost/hindi/level3/ice_cream_packet.mp3", false, 3},
    {"Imagesv4_compost/Level3/namkeen.png", "hint_soundsv4_compost/level3/namkeen_packet.m4a", "hint_soundsv4_compost/hindi/level3/namkeen_packet.mp3", false, 3},
    
    //Level4
    {"Imagesv4_compost/Level4/onion.jpg", "hint_soundsv4_compost/level4/onion.m4a", "hint_soundsv4_compost/hindi/level4/onion.mp3", true, 4},
    {"Imagesv4_compost/Level4/watermelon.jpg", "hint_soundsv4_compost/level4/watermelon.m4a", "hint_soundsv4_compost/hindi/level4/watermelon.mp3", true, 4},

    {"Imagesv4_compost/Level4/roti.png", "hint_soundsv4_compost/level4/roti.m4a", "hint_soundsv4_compost/hindi/level4/roti.mp3", false, 4},
    {"Imagesv4_compost/Level4/metal_bolt.jpg", "hint_soundsv4_compost/level4/bolt.m4a", "hint_soundsv4_compost/hindi/level4/metal_bolt.mp3", false, 4},
    {"Imagesv4_compost/Level4/metallic_nut.jpg", "hint_soundsv4_compost/level4/nut.m4a", "hint_soundsv4_compost/hindi/level4/metal_bolt.mp3", false, 4},
    {"Imagesv4_compost/Level4/nut.jpg", "hint_soundsv4_compost/level4/nut.m4a", "hint_soundsv4_compost/hindi/level4/metal_bolt.mp3", false, 4},
    {"Imagesv4_compost/Level4/pin.jpg", "hint_soundsv4_compost/level4/pin.m4a", "hint_soundsv4_compost/hindi/level4/metal_pin.mp3",false, 4},
    {"Imagesv4_compost/Level4/spoon_rusted.jpg", "hint_soundsv4_compost/level4/spoon.m4a", "hint_soundsv4_compost/hindi/level4/spoon.mp3", false, 4},
    {"Imagesv4_compost/Level4/plastic_bag_green.jpg", "hint_soundsv4_compost/level4/bag.m4a", "hint_soundsv4_compost/hindi/level4/plastic_bag.mp3", false, 4},
    {"Imagesv4_compost/Level4/rusted_metal.jpg", "hint_soundsv4_compost/level4/keys.m4a", "hint_soundsv4_compost/hindi/level4/metal_keys.mp3", false, 4},
    {"Imagesv4_compost/Level4/rusty_bolt.jpg", "hint_soundsv4_compost/level4/bolt.m4a", "hint_soundsv4_compost/hindi/level4/metal_bolt.mp3", false, 4},
    
    //Level5
    {"Imagesv4_compost/Level5/apple_waste.jpg", "hint_soundsv4_compost/level5/apple.m4a", "hint_soundsv4_compost/hindi/level5/apple.mp3", true, 5},
    {"Imagesv4_compost/Level5/leaf.jpg", "hint_soundsv4_compost/level5/leaf.m4a", "hint_soundsv4_compost/hindi/level5/leaves.mp3", true, 5},
    {"Imagesv4_compost/Level5/pear_peel.png", "hint_soundsv4_compost/level5/pear.m4a", "hint_soundsv4_compost/hindi/level5/pear.mp3", true, 5},
    {"Imagesv4_compost/Level5/paper_bits.jpg", "hint_soundsv4_compost/level5/paper.m4a", "hint_soundsv4_compost/hindi/level5/paper.mp3", true, 5},
    {"Imagesv4_compost/Level5/vegetable_waste2.jpg", "hint_soundsv4_compost/level5/vegetables.m4a", "hint_soundsv4_compost/hindi/level5/vegetable_waste.mp3", true, 5},
    {"Imagesv4_compost/Level5/wood_waste.jpg", "hint_soundsv4_compost/level5/wood.m4a", "hint_soundsv4_compost/hindi/level5/wood.mp3", true, 5},
    {"Imagesv4_compost/Level5/wood-flakes.jpg", "hint_soundsv4_compost/level5/wood.m4a", "hint_soundsv4_compost/hindi/level5/wood.mp3", true, 5},
    
    {"Imagesv4_compost/Level5/green_cap.png", "hint_soundsv4_compost/level5/bottle_cap.m4a", "hint_soundsv4_compost/hindi/level5/plastic_cap.mp3", false, 5},
    {"Imagesv4_compost/Level5/lemon_waste.jpg", "hint_soundsv4_compost/level5/lemon.m4a", "hint_soundsv4_compost/hindi/level5/lemon.mp3", false, 5},
    {"Imagesv4_compost/Level5/plastic_bottle_cap.jpg", "hint_soundsv4_compost/level5/bottle_cap.m4a", "hint_soundsv4_compost/hindi/level5/plastic_cap.mp3", false, 5},
    {"Imagesv4_compost/Level5/seeds.jpg", "hint_soundsv4_compost/level5/seed.m4a", "hint_soundsv4_compost/hindi/level5/seed.mp3", false, 5},
    {"Imagesv4_compost/Level5/seeds_2.jpg", "hint_soundsv4_compost/level5/seed.m4a", "hint_soundsv4_compost/hindi/level5/seed.mp3", false, 5}
    
};

const int LevelCompost::max_level_number = 5;
