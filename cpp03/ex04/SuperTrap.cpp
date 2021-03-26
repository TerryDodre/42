#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : NinjaTrap(1), FragTrap(1)
{
	this->_hit_point = FragTrap::_hit_point;
	this->_max_hit_point = FragTrap::_max_hit_point;
	this->_energy_point = NinjaTrap::_energy_point;
	this->_max_energy_point = NinjaTrap::_max_energy_point;
	this->_level = 1;
	this->_name = "Default";
	this->_melee_attack_dmg = NinjaTrap::_melee_attack_dmg;
	this->_ranged_attack_dmg = FragTrap::_ranged_attack_dmg;
	this->_armor_dmg_reduction = FragTrap::_armor_dmg_reduction;
	srand(time(0));
	std::cout << "New ClapTrap is coming, heemerges from the shadows, his name is " 
	<< this->_name << "." << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string name) : NinjaTrap(1), FragTrap(1)
{
	this->_hit_point = FragTrap::_hit_point;
	this->_max_hit_point = FragTrap::_max_hit_point;
	this->_energy_point = NinjaTrap::_energy_point;
	this->_max_energy_point = NinjaTrap::_max_energy_point;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_dmg = NinjaTrap::_melee_attack_dmg;
	this->_ranged_attack_dmg = FragTrap::_ranged_attack_dmg;
	this->_armor_dmg_reduction = FragTrap::_armor_dmg_reduction;
	srand(time(0));
	std::cout << "New ClapTrap is coming, heemerges from the shadows, his name is " 
	<< this->_name << "." << std::endl;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "Oh my god !!! " << std::endl;
	return;
}

SuperTrap::SuperTrap(const SuperTrap &s)
{
	*this = s;
	std::cout << this->_name << " has just been copied." << std::endl;
}

SuperTrap	&SuperTrap::operator=(const SuperTrap &s)
{
	if (this == &s)
		return (*this);
	ClapTrap::operator=(s);
	return (*this);
}

void		SuperTrap::rangedAttack(std::string target)
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string target)
{
	NinjaTrap::meleeAttack(target);
}
