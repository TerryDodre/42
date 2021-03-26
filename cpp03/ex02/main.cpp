#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

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
	std::cout << std::endl;

	std::cout << "/////////////////////////////////////\n" << std::endl;

	ScavTrap	Blip = ScavTrap("Blip");
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		Blip.challengeNewcomer();
		std::cout << std::endl;
	}
	Blip.meleeAttack("Bad dog");
	Blip.rangedAttack("Bad dog");
	Blip.takeDamage(50);
	std::cout << std::endl;
	Blip.beRepaired(25);
	std::cout << std::endl;
	Blip.takeDamage(1000);
	std::cout << std::endl;
	Blip.beRepaired(1000);
	std::cout << std::endl;
	return (0);
}
