// to enable CCLOG()
#define COCOS2D_DEBUG 1

#include "cocos2d.h"
#include "FileOperation.h"
#include <stdio.h>
#include <fstream>
using namespace std;

void FileOperation::saveFile(string filename, string content)
{
	//string path = getFilePath();

    //using C standard library
//    string path = cocos2d::FileUtils::sharedFileUtils()->getWritablePath() + "/" + filename;
//    FILE *fp = fopen(path.c_str(), "w");
//
//	if (! fp)
//	{
//		CCLOG("can not create file %s", path.c_str());
//		return;
//	}
//
//	fputs(content.c_str(), fp);
//	fclose(fp);

    //using C++ standard library
    string path = cocos2d::FileUtils::sharedFileUtils()->getWritablePath() + "/" + filename;
    ofstream ofile;
    ofile.open(path);
    if(!ofile){
        CCLOG("can not create file %s", path.c_str());
        return;
    }
    ofile<<content;
    ofile.close();
}

string FileOperation::readFile(string filename)
{
	//string path = getFilePath();

    //using C standard library
//    string path = cocos2d::FileUtils::sharedFileUtils()->getWritablePath() + "/" + filename;
//    FILE *fp = fopen(path.c_str(), "r");
//	char buf[50] = {0};
//
//	if (! fp)
//	{
//		CCLOG("can not open file %s", path.c_str());
//		return string("can not open file");
//	}
//
//	fgets(buf, 50, fp);
//	CCLOG("read content %s", buf);
//
//	fclose(fp);
//    return string(buf);

    //using C++ standard library
    string path = cocos2d::FileUtils::sharedFileUtils()->getWritablePath() + "/" + filename;
    ifstream ifile;
    ifile.open(path);
    if(!ifile){
        CCLOG("can not open file %s", path.c_str());
        return string("can not open file");
    }
    
    stringstream buffer;
    buffer<<ifile.rdbuf();
    return buffer.str();
}

bool FileOperation::fileExists(string filename){
    string path = cocos2d::FileUtils::sharedFileUtils()->getWritablePath() + "/" + filename;
    ifstream ifile;
    ifile.open(path);
    if(!ifile){
        CCLOG("can not open file %s", path.c_str());
        return false;
    }
    
    //stringstream buffer;
    //buffer<<ifile.rdbuf();
    return true;
}

//string FileOperation::getFilePath()
//{
//	string path("");
//    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	// In android, every programe has a director under /data/data.
//	// The path is /data/data/ + start activity package name.
//	// You can save application specific data here.
//	path.append("/data/data/org.cocos2dx.application/tmpfile");
//#endif
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//	// You can save file in anywhere if you have the permision.
//	path.append("D:/tmpfile");
//#endif
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
//	path = cocos2d::CCApplication::sharedApplication().getAppDataPath();
//
//#ifdef _TRANZDA_VM_
//	// If runs on WoPhone simulator, you should insert "D:/Work7" at the
//	// begin. We will fix the bug in no far future.
//	path = "D:/Work7" + path;
//	path.append("tmpfile");
//#endif
//
//#endif
//
//	return path;
//}
