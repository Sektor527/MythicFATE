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

void rollEvent()
{
	std::vector<std::string> focus;
	focus.insert(focus.end(), 7, "Remote event");
	focus.insert(focus.end(), 28 - focus.size(), "NPC action");
	focus.insert(focus.end(), 35 - focus.size(), "Introduce a new NPC");
	focus.insert(focus.end(), 45 - focus.size(), "Move toward a thread");
	focus.insert(focus.end(), 52 - focus.size(), "Move away from a thread");
	focus.insert(focus.end(), 55 - focus.size(), "Close a thread");
	focus.insert(focus.end(), 67 - focus.size(), "PC negative");
	focus.insert(focus.end(), 75 - focus.size(), "PC positive");
	focus.insert(focus.end(), 83 - focus.size(), "Ambiguous event");
	focus.insert(focus.end(), 92 - focus.size(), "NPC negative");
	focus.insert(focus.end(), 100 - focus.size(), "NPC positive");

	std::vector<std::string> action;
	action.push_back("Attainment");
	action.push_back("Starting");
	action.push_back("Neglect");
	action.push_back("Fight");
	action.push_back("Recruit");
	action.push_back("Triumph");
	action.push_back("Violate");
	action.push_back("Oppose");
	action.push_back("Malice");
	action.push_back("Communicate");
	action.push_back("Persecute");
	action.push_back("Increase");
	action.push_back("Decrease");
	action.push_back("Abandon");
	action.push_back("Gratify");
	action.push_back("Inquire");
	action.push_back("Antagonise");
	action.push_back("Move");
	action.push_back("Waste");
	action.push_back("Truce");
	action.push_back("Release");
	action.push_back("Befriend");
	action.push_back("Judge");
	action.push_back("Desert");
	action.push_back("Dominate");
	action.push_back("Procrastinate");
	action.push_back("Praise");
	action.push_back("Separate");
	action.push_back("Take");
	action.push_back("Break");
	action.push_back("Heal");
	action.push_back("Delay");
	action.push_back("Stop");
	action.push_back("Lie");
	action.push_back("Return");
	action.push_back("Immitate");
	action.push_back("Struggle");
	action.push_back("Inform");
	action.push_back("Bestow");
	action.push_back("Postpone");
	action.push_back("Expose");
	action.push_back("Haggle");
	action.push_back("Imprison");
	action.push_back("Release");
	action.push_back("Celebrate");
	action.push_back("Develop");
	action.push_back("Travel");
	action.push_back("Block");
	action.push_back("Harm");
	action.push_back("Debase");
	action.push_back("Overindulge");
	action.push_back("Adjourn");
	action.push_back("Adversity");
	action.push_back("Kill");
	action.push_back("Disrupt");
	action.push_back("Usurp");
	action.push_back("Create");
	action.push_back("Betray");
	action.push_back("Agree");
	action.push_back("Abuse");
	action.push_back("Oppress");
	action.push_back("Inspect");
	action.push_back("Ambush");
	action.push_back("Spy");
	action.push_back("Attach");
	action.push_back("Carry");
	action.push_back("Open");
	action.push_back("Carelessness");
	action.push_back("Ruin");
	action.push_back("Extravagance");
	action.push_back("Trick");
	action.push_back("Arrive");
	action.push_back("Propose");
	action.push_back("Divide");
	action.push_back("Refuse");
	action.push_back("Mistrust");
	action.push_back("Deceive");
	action.push_back("Cruelty");
	action.push_back("Intolerance");
	action.push_back("Trust");
	action.push_back("Excitement");
	action.push_back("Activity");
	action.push_back("Assist");
	action.push_back("Care");
	action.push_back("Negligence");
	action.push_back("Passion");
	action.push_back("Work hard");
	action.push_back("Control");
	action.push_back("Attract");
	action.push_back("Failure");
	action.push_back("Pursue");
	action.push_back("Vengeance");
	action.push_back("Proceedings");
	action.push_back("Dispute");
	action.push_back("Punish");
	action.push_back("Guide");
	action.push_back("Transform");
	action.push_back("Overthrow");
	action.push_back("Oppress");
	action.push_back("Change");

	std::vector<std::string> subject;
	subject.push_back("goals");
	subject.push_back("dreams");
	subject.push_back("environment");
	subject.push_back("outside");
	subject.push_back("inside");
	subject.push_back("reality");
	subject.push_back("allies");
	subject.push_back("enemies");
	subject.push_back("evil");
	subject.push_back("good");
	subject.push_back("emotions");
	subject.push_back("opposition");
	subject.push_back("war");
	subject.push_back("peace");
	subject.push_back("the innocent");
	subject.push_back("love");
	subject.push_back("the spiritual");
	subject.push_back("the intellectual");
	subject.push_back("new ideas");
	subject.push_back("joy");
	subject.push_back("messages");
	subject.push_back("energy");
	subject.push_back("balance");
	subject.push_back("tension");
	subject.push_back("friendship");
	subject.push_back("the physical");
	subject.push_back("a project");
	subject.push_back("pleasures");
	subject.push_back("pain");
	subject.push_back("possessions");
	subject.push_back("benefits");
	subject.push_back("plans");
	subject.push_back("lies");
	subject.push_back("expectations");
	subject.push_back("legal matters");
	subject.push_back("bureaucracy");
	subject.push_back("business");
	subject.push_back("a path");
	subject.push_back("news");
	subject.push_back("exterior factors");
	subject.push_back("advice");
	subject.push_back("a plot");
	subject.push_back("competition");
	subject.push_back("prison");
	subject.push_back("illness");
	subject.push_back("food");
	subject.push_back("attention");
	subject.push_back("success");
	subject.push_back("failure");
	subject.push_back("travel");
	subject.push_back("jealousy");
	subject.push_back("dispute");
	subject.push_back("home");
	subject.push_back("investment");
	subject.push_back("suffering");
	subject.push_back("wishes");
	subject.push_back("tactics");
	subject.push_back("stalemate");
	subject.push_back("randomness");
	subject.push_back("misfortune");
	subject.push_back("death");
	subject.push_back("disruption");
	subject.push_back("power");
	subject.push_back("a burden");
	subject.push_back("intrigues");
	subject.push_back("fears");
	subject.push_back("ambush");
	subject.push_back("rumor");
	subject.push_back("wounds");
	subject.push_back("extravagance");
	subject.push_back("a representative");
	subject.push_back("adversities");
	subject.push_back("opulence");
	subject.push_back("liberty");
	subject.push_back("military");
	subject.push_back("the mundane");
	subject.push_back("trials");
	subject.push_back("masses");
	subject.push_back("vehicle");
	subject.push_back("art");
	subject.push_back("victory");
	subject.push_back("dispute");
	subject.push_back("riches");
	subject.push_back("status quo");
	subject.push_back("technology");
	subject.push_back("hope");
	subject.push_back("magic");
	subject.push_back("illusions");
	subject.push_back("portals");
	subject.push_back("danger");
	subject.push_back("weapons");
	subject.push_back("animals");
	subject.push_back("weather");
	subject.push_back("elements");
	subject.push_back("nature");
	subject.push_back("the public");
	subject.push_back("leadership");
	subject.push_back("fame");
	subject.push_back("anger");
	subject.push_back("information");

	std::cout << " " << focus[rand() % 100] << ": " << action[rand() % 100] << " " << subject[rand() % 100];
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

	if (strcmp(*argv, "event") == 0)
	{
		rollEvent();
		return 0;
	}
	
	printUsage();

	return 0;
}
