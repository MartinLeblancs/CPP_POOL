//
// Created by mqueru on 1/31/22.
//

#include "../include/IMonitorModule.hpp"
#include "../include/IMonitorDisplay.hpp"

void core(char *arg)
{
	if (strcmp(arg, "-help") == 0)
		Display::displayHelp();
	else if (strcmp(arg, "-g") == 0)
		Display::displayGraphicSfml();
	else if (strcmp(arg, "-t") == 0)
		Display::displayNCurse();
	else {
		std::cerr << "ERROR: invalid command, try with -help" << std::endl;
		exit(84);
	}
}

void Display::displayHelp()
{
	std::cout << "Usage : ./MyGKrellm [option]" << std::endl << "Option: -g (graphic mod) ; -t (text mod)" << std::endl;
}

