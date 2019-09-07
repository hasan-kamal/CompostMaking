#ifndef __HELLOWORLD_FILE_OPERATION__
#define __HELLOWORLD_FILE_OPERATION__

#include <string>
using namespace std;

class FileOperation 
{
public:
	static void saveFile(string filename, string content);
	static string readFile(string filename);
    static bool fileExists(string filename);
	//static std::string getFilePath();
};

#endif
