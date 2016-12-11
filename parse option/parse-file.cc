// reading a text file
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <inttypes.h>	// int32_t, uint32_t
#include <algorithm>
using namespace std;

// config-file: <option> = <content>
// ex in config file:
// PRINT_MONITOR=true
// DEBUG_LEVEL=2
// ###############
// use '#' for comment line

#define NUM_ROW(ARG) (sizeof(ARG)/sizeof(ARG[0][0])/2)

bool ToBool(const std::string str);
bool ToInt(const std::string &str, int32_t &result);
uint32_t ToUint(const std::string &str);
float ToFloat(const std::string &str);
double ToDouble(const std::string &str);

class ParseFile {

public:
	ParseFile(const char *file);
	~ParseFile();
	bool ParseArgs(std::string args[][2], int maxSize);
	void PrintUsage();
	void PrintConfig();

private:
	int index;
	std::ifstream pfile;
	std::string fileName;
	std::string str;
};


int main () {

	std::string args[5][2];

 	ParseFile po("sys-config.cfg");
	po.ParseArgs(args,NUM_ROW(args));

	for (int i = 0; i < 5; i++)
	{
		std::cout << args[i][0] << ":" << args[i][1] << "\n";
	}
	int32_t xxx;

	ToInt(args[1][1], xxx);
	cout << "convert to int : " << xxx << "\n";
	return 0;
}

ParseFile::ParseFile(const char *file) {
	index = 0;
	fileName = file;
}

ParseFile::~ParseFile() {}

bool ParseFile::ParseArgs(std::string args[][2], int maxSize) {
	
	pfile.open(fileName.c_str());

	if (pfile.is_open()) {

		while ( getline (pfile, str) ) {
			if(*str.begin()=='#') // detect comment line
				continue;
			str.erase(std::remove(str.begin(), str.end(), ' '),str.end());	// remove whitespace
			str.erase(std::remove(str.begin(), str.end(), '\t'),str.end()); // remove tab

			int strLeng = str.length();
			if( (strLeng<2) || *str.begin()=='#')	// detect empty or line only contain tab .. or comment line
				continue;

			std::size_t found = str.find('=');
			if(found!=std::string::npos) {
				string header = str.substr(0,str.find('='));
				string content = str.substr(str.find('=')+1,strLeng);
				args[index][0] = header;
				args[index][1] = content;
				index++;
				
				if(index >= maxSize)
					return 1;
			}
		}
	} else {
		std::cout << "Unable to open file \n";
		return 1;
	}

	pfile.close();
	return 0;
}

bool ToBool(const std::string str) {
	if(strcmp(str.c_str(),"true")==0) {
		return true;
	}
	else if (strcmp(str.c_str(),"false")==0) {
		return false;
	}
}

bool ToInt(const std::string& str, int32_t &result) {
	try {
	  std::size_t lastChar;
	  result = std::stoi(str, &lastChar, 10);
	  return lastChar == str.size();
	} 
	catch (std::invalid_argument&) {
	  return false;
	}
	catch (std::out_of_range&) {
	  return false;
	}
}