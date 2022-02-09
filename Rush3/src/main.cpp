//
// Created by mqueru on 1/31/22.
//

#include "../include/IMonitorModule.hpp"

int main(int ac, char **av, char **env)
{
	if (env == NULL)
		return 84;
	if (ac != 2) {
		std::cerr << "ERROR: invalid command, try -help" << std::endl;
		return 84;
	}
	core(av[1]);
	return 0;
}