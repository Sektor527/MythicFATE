#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>

#if WIN32
#include <process.h>
#define getpid() _getpid()
#endif

void printUsage()
{
	std::cout << std::endl;
	std::cout << "MythicFATE dice roller, copyright 2014 Wim Vanherle" << std::endl << std::endl;
	std::cout << "Usage:" << std::endl << std::endl;
	std::cout << "  fate check                    roll four FATE dice" << std::endl;
	std::cout << "  fate yes <odds> <chaos>       roll for a yes/no answer, where <odds> is in [-4,6] and <chaos> is in [1,9]" << std::endl;
	std::cout << "  fate event                    create a random event" << std::endl;
	std::cout << std::endl;
}

void rollFateDice()
{
	std::vector<char> values;
	values.push_back('+');
	values.push_back('-');
	values.push_back(' ');

	for (int i = 0; i < 4; ++i)
	{
		char value = values[rand() % values.size()];
		std::cout << " [" << value << "]";
	}
}

int main(int argc, char** argv)
{
	srand(time(NULL) * getpid());

	// Parse arguments
	argc--; argv++;

	if (argc == 0)
	{
		printUsage();
		return -1;
	}

	if (strcmp(*argv, "check") == 0)
	{
		rollFateDice();
		return 0;
	}

	printUsage();

	return 0;
}
