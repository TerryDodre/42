#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

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

	ScavTrap	Pilb = ScavTrap("Pilb");
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		Pilb.challengeNewcomer();
		std::cout << std::endl;
	}
	Pilb.meleeAttack("Bad dog");
	Pilb.rangedAttack("Bad dog");
	Pilb.takeDamage(50);
	std::cout << std::endl;
	Pilb.beRepaired(25);
	std::cout << std::endl;
	Pilb.takeDamage(1000);
	std::cout << std::endl;
	Pilb.beRepaired(1000);
	std::cout << std::endl;

	std::cout << "/////////////////////////////////////\n" << std::endl;

	NinjaTrap	Blap = NinjaTrap("Blap");
	std::cout << std::endl;
	Blap.ninjaShoebox(Blap);
	std::cout << std::endl;
	Blap.ninjaShoebox(Pilb);
	std::cout << std::endl;
	Blap.ninjaShoebox(Blop);
	std::cout << std::endl;
	Blap.takeDamage(50);
	std::cout << std::endl;
	Blap.beRepaired(25);
	std::cout << std::endl;
	Blap.takeDamage(1000);
	std::cout << std::endl;
	Blap.beRepaired(1000);
	std::cout << std::endl;
	return (0);
}
