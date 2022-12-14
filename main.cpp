#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include "dirent.h"

std::string search_algorithm(std::string keyword) {
	std::string output;
	std::string line;
	struct dirent* en;
	DIR* dr;
	dr = opendir("db/");
	if (dr) {
		while ((en = readdir(dr)) != NULL) {
			std::string filename = std::string(en->d_name);
			std::string filepath = std::string("db/") + filename;
			if (filename == "." || filename == "..") {
			}
			else {
				std::ifstream file;
				file.open(filepath);
				if (file.is_open()) {
					while (getline(file, line)) {
						if (line.find(keyword) != std::string::npos) {
							output = output + line + "\n";
						}
					}
				}
				file.close();
			}
		}
	}
	return output;
}

int main(int argc, char** args) {
	std::cout << search_algorithm("1.1.1.1");
	return 1;
}
