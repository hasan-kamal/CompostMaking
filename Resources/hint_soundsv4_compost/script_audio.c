#include <stdlib.h>
#include <stdio.h>
#define MAX_OBJECTS 100
#define STR_LEN 1000

typedef struct{
	char *text_to_speech;
	char *ofilename;
	int can_put_in_compost;
	int level_number;
} entry;

int num_objects = 44;
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
	*/

	//Level3
	{"Banana", "banana", 1, 3},
	{"Bread", "bread", 1, 3},
	{"Cucumber", "cucumber", 1, 3},
	{"Egg shell", "egg_shell", 1, 3},
	
	{"Chips packet", "chips_packet", 0, 3},
	{"Ice cream packet", "ice_cream_packet", 0, 3},
	{"Namkeen packet", "namkeen_packet", 0, 3},
	{"Toffee wrapper", "toffee_wrapper", 0, 3},
	{"Chocolate wrapper", "chocolate_wrapper", 0, 3},
	{"Rice", "rice", 0, 3},
	/*
		{"Level3/banana_peel.jpg", "", true, 3},
	*/

	//Level4
	{"Biscuit", "biscuit", 1, 4},
	{"Onion", "onion", 1, 4},
	{"Watermelon", "watermelon", 1, 4},

	{"Metal Bolt", "bolt", 0, 4},
	{"Metal keys", "keys", 0, 4},
	{"Metal nut", "nut", 0, 4},
	{"Metal pin", "pin", 0, 4},
	{"Metal spoon", "spoon", 0, 4},
	{"Roti", "roti", 0, 4},
	{"Plastic bag", "bag", 0, 4},
	
	/*
		{"Level4/biscuit.jpg", "", true, 4},
	*/

	//Level5
	{"Apple", "apple", 1, 5},
	{"Leaf", "leaf", 1, 5},
	{"Pear", "pear", 1, 5},
	{"Paper", "paper", 1, 5},
	{"Vegetables", "vegetables", 1, 5},
	{"Wood pieces", "wood", 1, 5},

	{"Lemon", "lemon", 0, 5},
	{"Bottle cap", "bottle_cap", 0, 5},
	{"Seed", "seed", 0, 5}
	/*
		{"Level5/apple_waste.jpg", "", true, 5},
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
		sprintf(suffix, list_text[i].can_put_in_compost?", can be put in compost":", can NOT, be put in compost");
		sprintf(path_out, "level%d/%s", list_text[i].level_number, list_text[i].ofilename);
		sprintf(command, "say \"%s%s\" -o \"%s.m4a\" ", list_text[i].text_to_speech, suffix, path_out);
		puts(command);
		system(command);
	}

	return 0;
}