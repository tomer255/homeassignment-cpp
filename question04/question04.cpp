//Question 4 - Filesystem & args  

// Task: Implement the code as described in the main body, make sure to handle cases when the requested file is not found or the "files" directory doesn't exists and you have to create it
// Prefer modern solutions over classic C style solutions and keep in mind that this code should be able to run in other windows, linux and other platforms (hint: '/' and '\' in file paths)


#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <direct.h>

#if defined(WIN32) || defined(_WIN32) 
#define PATH_SEPARATOR "\\" 
#else 
#define PATH_SEPARATOR "/" 
#endif 

int main(int argc, char** argv)
{
	std::string commend;
	std::cout << "Enter create or read" << std::endl;
	std::cin >> commend;
	std::string folder = std::string(".") + PATH_SEPARATOR + "files";
	std::string file = "argument2.txt";
	std::string path =  folder + PATH_SEPARATOR + file;
	//If user passed "create" argument 
	//		Create (or overwrite) a file named *argument2.txt*  with the text "Hello from *argument3*" in a folder named "files" under the current working directory  
	if (commend == "create") {
		std::ofstream file;
		// Create a directory if it doesn't exist
		if (!std::filesystem::is_directory(folder)) {
			std::filesystem::create_directory(folder);
			std::cout << "Create Directory" << std::endl;
		}
		file.open(path);
		if (file.is_open())
		{
			file << "Hello from *argument3*";
			file.close();
		}
		else {
			std::cout << "Unable to open file" << std::endl;
		}
	}
	//else if user passed "read" argument 
	//		read a file named* argument2* from a folder named "files" under the current working directory and print it to the console
	else if (commend == "read") {
		std::ifstream file;
		file.open(path);
		std::string line;
		if (file.is_open())
		{
			while (getline(file, line))
			{
				std::cout << line << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "Unable to open file" << std::endl;
		}
	}
	//Execution example (assuming working directory c:\code): question04.exe create test1 Nir - should create the file c:\code\files\test1.txt with the content "Hello from Nir"
	//Execution example (assuming working directory c:\code): question04.exe read test1  - should print "Hello from Nir" in the console (assuming the previous command was executed) 

	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}