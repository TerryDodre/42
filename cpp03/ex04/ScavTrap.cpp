#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hit_point = 100;
	this->_max_hit_point = 100;
	this->_energy_point = 50;
	this->_max_energy_point = 50;
	this->_level = 1;
	this->_name = "Default";
	this->_melee_attack_dmg = 20;
	this->_ranged_attack_dmg = 15;
	this->_armor_dmg_reduction = 3;
	srand(time(0));
	std::cout << " - [" << this->_name
	<< "] \"Hello! I am your new steward bot, my name is "<< this->_name 
	<< "." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	this->_hit_point = 100;
	this->_max_hit_point = 100;
	this->_energy_point = 50;
	this->_max_energy_point = 50;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_dmg = 20;
	this->_ranged_attack_dmg = 15;
	this->_armor_dmg_reduction = 3;
	srand(time(0));
	std::cout << " - [" << this->_name
	<< "] \"Hello! I am your new steward bot, my name is "<< this->_name 
	<< "." << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "What ?!? " << this->_name << " destroyed himself." 
	<< std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap(s)
{
	*this = s;
	std::cout << this->_name << " has just been copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &s)
{
	if (this == &s)
		return (*this);
	ClapTrap::operator=(s);
	return (*this);
}

void		ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SCAV-TP " << this->_name << " attacks " << target
	<< " at range, causing " << this->_ranged_attack_dmg
	<< " points of damage! Take that! Take that!" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SCAV-TP " << this->_name << " attacks " << target
	<< " at melee, causing " << this->_melee_attack_dmg
	<< " points of damage! Heyyah!" << std::endl;
}

void        ScavTrap::challengeNewcomer(void)
{
    int             rand;
	std::string		random_chal[5] = {"Pod Pew Pew",
						"Hit-and-Fun", 
						"Purple Reign", 
						"Dolla Dolla Bills, Y'all", 
						"This is No Time for Lazy!"};
	std::string		random_str[2] = {"Oh my gosh, a challenge", 
						"I actually did something right for once!"};

	if (this->_energy_point < 25)
	{
		std::cout << "SCAV-TP " << this->_name
		<< " does nothing because it has no more energy." << std::endl;
		std::cout << " - [" << this->_name << "] \"Does this mean I can " 
		<< "start dancing? Pleeeeeeaaaaase?\"" << std::endl;
		return;
	}
	this->_energy_point -= 25;
	this->_energy_point < 0 ? this->_energy_point = 0 : 0;
	rand = std::rand() % 5;
	std::cout << "SCAV-TP " << this->_name << " load the challenge : "
	<< random_chal[rand] << "!!!" << std::endl;
    std::cout << " - [" << this->_name << "] "
	<< random_str[rand % 2] << "\"" << std::endl;
}
