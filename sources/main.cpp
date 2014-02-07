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

#define VALIDATE(x) if (!(x)) { printUsage(); exit(EXIT_FAILURE); }

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

void rollYesNo(int odds, int chaos)
{
	odds += 4;
	chaos = 9 - chaos;

	std::string oddsLabels[11] = {
		"Impossible",
		"No way",
		"Very unlikely",
		"Unlikely",
		"50/50",
		"Somewhat likely",
		"Likely",
		"Very likely",
		"Near sure thing",
		"A sure thing",
		"Has to be"
	};

	char chart[11 * 9] = {
		 50,  25,  15,  10,   5,   5,   0,   0, -20, // Impossible
		 75,  50,  35,  25,  15,  10,   5,   5,   0, // No way
		 85,  65,  50,  45,  25,  15,  10,   5,   5, // Very unlikely
		 90,  75,  55,  50,  35,  20,  15,  10,   5, // Unlikely
		 95,  85,  75,  65,  50,  35,  25,  15,  10, // 50/50
		 95,  90,  85,  80,  65,  50,  45,  25,  20, // Somewhat likely
		100,  95,  90,  85,  75,  55,  50,  35,  25, // Likely
		105,  95,  95,  90,  85,  75,  65,  50,  45, // Very likely
		115, 100,  95,  95,  90,  80,  75,  55,  55, // Near sure thing
		125, 110,  95,  95,  90,  85,  80,  65,  55, // A sure thing
		145, 130, 100, 100,  95,  95,  90,  85,  80  // Has to be
	};

	int value = chart[9 * odds + chaos];
	int roll = rand() % 100 + 1;
	
	std::cout << " " << oddsLabels[odds] << ":  ";
	if (roll <= value / 5)
		std::cout << "Exceptional yes!";
	else if (roll <= value)
		std::cout << "Yes";
	else if (roll <= 100 - (100 - value) / 5)
		std::cout << "No";
	else
		std::cout << "Exceptional no!";
}

int main(int argc, char** argv)
{
	srand(time(NULL) * getpid());

	// Parse arguments
	argc--; argv++;
	VALIDATE(argc != 0);

	if (strcmp(*argv, "check") == 0)
	{
		rollFateDice();
		return 0;
	}

	if (strcmp(*argv, "yes") == 0)
	{
		argc--; argv++;
		VALIDATE(argc == 2);

		int odds, chaos;
		VALIDATE(std::stringstream(std::string(*(argv))) >> odds);
		VALIDATE(std::stringstream(std::string(*(argv+1))) >> chaos);
		VALIDATE(odds >= -4 && odds <= 6);
		VALIDATE(chaos >= 1 && chaos <= 9);

		rollYesNo(odds, chaos);
		return 0;
	}
	
	printUsage();

	return 0;
}
