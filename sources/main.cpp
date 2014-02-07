#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>

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

int main(int argc, char** argv)
{
	// Parse arguments
	argc--; argv++;

	if (argc == 0)
	{
		printUsage();
		return -1;
	}

	return 0;
}
