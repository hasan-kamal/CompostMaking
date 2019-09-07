//
//  Level.cpp
//  CompostIdentification
//
//  Created by Hasan Kamal on 20/01/17.
//
//

#include "Level.hpp"

const vector<pair<vector<string>, vector<string> > > Level::images{
    
    pair<vector<string>, vector<string> >({"Level1/coriander_leaves.png", "Level1/dry_leaf.png", "Level1/peas_pod.png", "Level1/potato_peel.png"}, {"Level1/transparent_cup.png", "Level1/transparent_plastic_bag_2.png", "Level1/transparent_plastic_bag.png", "Level1/transparent_plastic_bottle_2.png", "Level1/transparent_plastic_bottle.png", "Level1/transparent_plastic_container_2.png", "Level1/transparent_plastic_container.png"}),
    
    pair<vector<string>, vector<string> >({"Level2/carrot_peel_2.png", "Level2/carrot_peel.png", "Level2/potato_peel_2.png", "Level2/potato_peel_3.png"}, {"Level2/coke_bottle.png", "Level2/colored_plastic_bag.png", "Level2/colored_plastic_bottle_2.png", "Level2/colored_plastic_bottle_3.png", "Level2/colored_plastic_bottles.png", "Level2/colored_plastic_container_2.png", "Level2/colored_plastic_containers.png"}),
    
    pair<vector<string>, vector<string> >({"Level3/banana_peel.png", "Level3/bread.png", "Level3/cucumber_peel.png", "Level3/egg-shell.png", "Level3/rice.jpg"}, {"Level3/chips_packet_2.png", "Level3/chips_packet_3.png", "Level3/chips_packet.png", "Level3/ice_cream_packet.png", "Level3/namkeen.png", "Level3/biscuit-main.png"}),
    
    pair<vector<string>, vector<string> >({"Level4/biscuit.png", "Level4/onion.png", "Level4/roti.png", "Level4/watermelon.png"}, {"Level4/bolt.png", "Level4/keys.png", "Level4/metal_bolt.png", "Level4/metallic_nut.png", "Level4/nut.png", "Level4/pin.png", "Level4/spoon.png"}),
    
    pair<vector<string>, vector<string> >({"Level5/apple_waste.png", "Level5/leaf.png", "Level5/pear_peel.png"}, {"Level5/lemon_waste.png", "Level5/plastic_bag.png", "Level5/plastic_bottle_cap.png", "Level5/seeds.png", "Level5/seeds_2.png"})
    
};

const int Level::max_level_number = 5;
