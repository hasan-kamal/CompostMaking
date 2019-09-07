#include <stdlib.h>
#include <stdio.h>
#define MAX_OBJECTS 100
#define STR_LEN 1000

typedef struct{
	char *text_to_speech;
	char *ofilename;
	int is_biodegradable;
	int level_number;
} entry;

int num_objects = 38;
int num_levels = 5;

entry list_text[MAX_OBJECTS] = {

	//Level1
	{"Coriander", "coriander", 1, 1},
	{"Leaf", "leaf", 1, 1},
	{"Pea", "pea", 1, 1},
	{"Potato", "potato", 1, 1},
	
	{"Plastic cup", "cup", 0, 1},
	{"Plastic bag", "bag", 0, 1},
	{"Plastic bottle", "bottle", 0, 1},
	{"Plastic container", "container", 0, 1},

	/*
		{"Level1/coriander_leaves.png", "hint_sounds/level1/coriander.m4a", true, 1},
		{"Level1/dry_leaf.png", "hint_sounds/level1/leaf.m4a", true, 1},
		{"Level1/peas_pod.png", "hint_sounds/level1/pea.m4a", true, 1},
		{"Level1/potato_peel.png", "hint_sounds/level1/potato.m4a", true, 1},

		{"Level1/transparent_cup.png", "hint_sounds/level1/cup.m4a", false, 1},
		{"Level1/transparent_plastic_bag_2.png", "hint_sounds/level1/bag.m4a", false, 1},
		{"Level1/transparent_plastic_bag.png", "hint_sounds/level1/bag.m4a", false, 1},
		{"Level1/transparent_plastic_bottle_2.png", "hint_sounds/level1/bottle.m4a", false, 1},
		{"Level1/transparent_plastic_bottle.png", "hint_sounds/level1/bottle.m4a", false, 1},
		{"Level1/transparent_plastic_container_2.png", "hint_sounds/level1/container.m4a", false, 1},
		{"Level1/transparent_plastic_container.png", "hint_sounds/level1/container.m4a", false, 1},
	*/
	
	//Level2
	{"Carrot", "carrot", 1, 2},
	{"Potato", "potato", 1, 2},

	{"Coke bottle", "coke_bottle", 0, 2},
	{"Plastic bag", "bag", 0, 2},
	{"Plastic bottle", "bottle", 0, 2},
	{"Dettol bottle", "dettol_bottle", 0, 2},
	{"Plastic container", "container", 0, 2},

	/*
		{"Level2/carrot_peel_2.jpg", "", true, 2},
		{"Level2/carrot_peel.jpg", "", true, 2},
		{"Level2/potato_peel_2.jpg", "", true, 2},
		{"Level2/potato_peel_3.jpg", "", true, 2},

		{"Level2/coke_bottle.jpg", "", false, 2},
		{"Level2/colored_plastic_bag.jpg", "", false, 2},
		{"Level2/colored_plastic_bottle_2.jpg", "", false, 2},
		{"Level2/colored_plastic_bottle_3.jpg", "", false, 2},
		{"Level2/dettol_bottle.jpg", "", false, 2},
		{"Level2/colored_plastic_container_2.jpg", "", false, 2},
		{"Level2/colored_plastic_containers.jpg", "", false, 2},
	*/

	//Level3
	{"Banana", "banana", 1, 3},
	{"Bread", "bread", 1, 3},
	{"Cucumber", "cucumber", 1, 3},
	{"Egg shell", "egg_shell", 1, 3},
	{"Rice", "rice", 1, 3},

	{"Chips packet", "chips_packet", 0, 3},
	{"Toffee wrapper", "toffee_wrapper", 0, 3},
	{"Chocolate wrapper", "chocolate_wrapper", 0, 3},
	/*
		{"Level3/banana_peel.jpg", "", true, 3},
		{"Level3/bread.jpg", "", true, 3},
		{"Level3/cucumber_peel.jpg", "", true, 3},
		{"Level3/egg-shell.jpg", "", true, 3},
		{"Level3/rice.jpg", "", true, 3},

		{"Level3/chips_packet_2.jpg", "", false, 3},
		{"Level3/empty_candy_wrapper.jpg", "", false, 3},
		{"Level3/chips_packet.jpg", "", false, 3},
		{"Level3/snickers_wrapper.jpg", "", false, 3},
		{"Level3/toffee_wrapper.jpg", "", false, 3},
		{"Level3/wrappers.jpg", "", false, 3},
	*/

	//Level4
	{"Biscuit", "biscuit", 1, 4},
	{"Onion", "onion", 1, 4},
	{"Roti", "roti", 1, 4},
	{"Watermelon", "watermelon", 1, 4},

	{"Metal Bolt", "bolt", 0, 4},
	{"Metal keys", "keys", 0, 4},
	{"Metal nut", "nut", 0, 4},
	{"Metal pin", "pin", 0, 4},
	{"Spoon", "spoon", 0, 4},
	/*
		{"Level4/biscuit.jpg", "", true, 4},
		{"Level4/onion.jpg", "", true, 4},
		{"Level4/roti.png", "", true, 4},
		{"Level4/watermelon.jpg", "", true, 4},

		{"Level4/bolt.jpg", "", false, 4},
		{"Level4/keys.jpg", "", false, 4},
		{"Level4/metal_bolt.jpg", "", false, 4},
		{"Level4/metallic_nut.jpg", "", false, 4},
		{"Level4/nut.jpg", "", false, 4},
		{"Level4/pin.jpg", "", false, 4},
		{"Level4/spoon.jpg", "", false, 4},
	*/

	//Level5
	{"Apple", "apple", 1, 5},
	{"Leaf", "leaf", 1, 5},
	{"Pear", "pear", 1, 5},

	{"Lemon", "lemon", 0, 5},
	{"Bottle cap", "bottle_cap", 0, 5},
	{"Seed", "seed", 0, 5}
	/*
		{"Level5/apple_waste.jpg", "", true, 5},
		{"Level5/leaf.jpg", "", true, 5},
		{"Level5/pear_peel.png", "", true, 5},

		{"Level5/lemon_waste.jpg", "", false, 5},
		{"Level5/lemon_waste_2.jpg", "", false, 5},
		{"Level5/plastic_bottle_cap.jpg", "", false, 5},
		{"Level5/seeds.jpg", "", false, 5},
		{"Level5/seeds_2.jpg", "", false, 5}
	*/
};

int main(){

	char command[STR_LEN];
	char suffix[STR_LEN];
	char path_out[STR_LEN];

	for(int i=0; i<num_levels; i++){
		sprintf(command, "mkdir level%d", i+1);
		puts(command);
		system(command);
	}

	for(int i=0; i<num_objects; i++){
		sprintf(suffix, list_text[i].is_biodegradable?", is biodegradable":", is NOT, biodegradable");
		sprintf(path_out, "level%d/%s", list_text[i].level_number, list_text[i].ofilename);
		sprintf(command, "say \"%s%s\" -o \"%s.m4a\" ", list_text[i].text_to_speech, suffix, path_out);
		puts(command);
		system(command);
	}

	return 0;
}