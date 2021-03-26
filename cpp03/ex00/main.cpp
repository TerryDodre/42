#include "FragTrap.hpp"

int			main(void)
{
	FragTrap	Blop = FragTrap("Blop");

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Blop.vaulthunter_dot_exe("Francky");
		std::cout << std::endl;
	}
	Blop.takeDamage(50);
	std::cout << std::endl;
	Blop.beRepaired(25);
	std::cout << std::endl;
	Blop.takeDamage(1000);
	std::cout << std::endl;
	Blop.beRepaired(1000);
	return (0);
}
