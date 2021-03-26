#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	this->_hit_point = 60;
	this->_max_hit_point = 60;
	this->_energy_point = 120;
	this->_max_energy_point = 120;
	this->_level = 1;
	this->_name = "Default";
	this->_melee_attack_dmg = 60;
	this->_ranged_attack_dmg = 5;
	this->_armor_dmg_reduction = 0;
	srand(time(0));
	std::cout << "A ClapTrap emerges from the shadows, his name is "
	<< this->_name << "." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap()
{
	this->_hit_point = 60;
	this->_max_hit_point = 60;
	this->_energy_point = 120;
	this->_max_energy_point = 120;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_dmg = 60;
	this->_ranged_attack_dmg = 5;
	this->_armor_dmg_reduction = 0;
	srand(time(0));
	std::cout << "A ClapTrap emerges from the shadows, his name is "
	<< this->_name << "." << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "Oh no ... " << this->_name << " fell from the roof."
	<< std::endl; 
	return;
}

NinjaTrap::NinjaTrap(const NinjaTrap &n) : ClapTrap(n)
{
	*this = n;
	std::cout << this->_name << " has just been copied." << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(const NinjaTrap &n)
{
	if (this == &n)
		return (*this);
	ClapTrap::operator=(n);
	return (*this);
}

void		NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "NINJA-TP " << this->_name << " attacks " << target
	<< " at range, causing " << this->_ranged_attack_dmg
	<< " points of damage with his shuriken!" << std::endl;
}

void		NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "NINJA-TP " << this->_name << " attacks " << target
	<< " at melee, causing " << this->_melee_attack_dmg
	<< " points of damage with his katana!" << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap &Ctrap)
{
	if (Ctrap.getName() == this->_name)
		std::cout << this->_name << " hid in his shoebox." << std::endl;
	else
	{
		std::cout << this->_name << " hid in " << Ctrap.getName()
		<< "\'s shoebox." << std::endl;
	}
}

void		NinjaTrap::ninjaShoebox(FragTrap &Ctrap)
{
	std::cout << this->_name << " hid in " << Ctrap.getName()
	<< "\'s shoebox." << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap &Ctrap)
{
	std::cout << this->_name << " hid in " << Ctrap.getName()
	<< "\'s shoebox." << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap &Ctrap)
{
	std::cout << this->_name << " hid in " << Ctrap.getName()
	<< "\'s shoebox." << std::endl;
}
