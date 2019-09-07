//
//  Statistics.cpp
//  JunkSort
//
//  Created by Hasan Kamal on 06/05/17.
//
//

#include "Statistics.hpp"
#include "FileOperation.h"
#include <string>

string Statistics::player_name = "";
string Statistics::filename = "db.txt";
bool Statistics::is_bio = false;

/*
static void saveFile(string filename, string content);
static string readFile(string filename);
static bool fileExists(string filename);
 */

void Statistics::save_stat(vector<int> num_correct, vector<int> num_incorrect){
    string s;
    s+=Statistics::player_name;
    s+="\n";
    s+=(Statistics::is_bio?"bio/non-bio mode":"compost/non-compost mode");
    s+="\n";
    char buffer[100];
    for(int i=0; i<num_incorrect.size(); i++){
//        s+="#"+std::stoi(i+1)+": "+std::to_string(num_incorrect[i])+", "+std::to_string(num_correct[i]+num_incorrect[i])+", ";
//        if(num_incorrect[i]+num_correct[i]!=0)
//            s+=std::to_string(num_correct[i]/(num_correct[i]+num_incorrect[i]+0.0)*100.0)+"%";
//        else
//            s+="--.--%";
        if(num_correct[i]+num_incorrect[i]==0)
            sprintf(buffer, "#%d: %9d, %5d, --.--%%", i+1, num_incorrect[i], num_incorrect[i]+num_correct[i]);
        else
            sprintf(buffer, "#%d: %9d, %5d, %2.2f%%", i+1, num_incorrect[i], num_incorrect[i]+num_correct[i], (num_correct[i])/(num_correct[i]+num_incorrect[i]+0.0)*100.0);
        s+=string(buffer);
        s+="\n";
    }
    s+="\n";
    
    if(FileOperation::fileExists(Statistics::filename)){
        string old = FileOperation::readFile(Statistics::filename);
        string new_string = s + old;
        FileOperation::saveFile(Statistics::filename, new_string);
    }else{
        FileOperation::saveFile(Statistics::filename, s);
    }
}

string Statistics::get_stat(){
    if(FileOperation::fileExists(Statistics::filename))
        return FileOperation::readFile(Statistics::filename);
    return "";
}
