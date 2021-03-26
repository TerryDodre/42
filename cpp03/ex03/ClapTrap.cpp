#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _hit_point(0), _max_hit_point(0), _energy_point(0),
		_max_energy_point(0), _level(0), _name("Default"),
		_melee_attack_dmg(0), _ranged_attack_dmg(0), _armor_dmg_reduction(0)
{
	std::cout << "A ClapTrap is under construction." << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Only bolts remain ..." << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	*this = c;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &c)
{
	if (this == &c)
		return (*this);
	this->_hit_point = c._hit_point;
	this->_max_hit_point = c._max_hit_point;
	this->_energy_point = c._energy_point;
	this->_max_energy_point = c._max_energy_point;
	this->_level = c._level;
	this->_name = c._name;
	this->_melee_attack_dmg = c._melee_attack_dmg;
	this->_ranged_attack_dmg = c._ranged_attack_dmg;
	this->_armor_dmg_reduction = c._armor_dmg_reduction;
	return (*this);
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	int		damage;

	damage = amount - this->_armor_dmg_reduction;
	damage < 0 ? damage = 0 : 0;
	this->_hit_point -= damage;
	this->_hit_point < 0 ? this->_hit_point = 0 : 0;
	std::cout << "CL4P-TP " << this->_name << " take " << damage 
	<< " points of damage! Now he has " << this->_hit_point 
	<< " life point." << std::endl;
	if (damage > 0)
	{
		std::cout << " - [" << this->_name << "] \"My robotic flesh! AAHH!\""
		<< std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_point += amount;
	this->_hit_point > this->_max_hit_point ? this->_hit_point = this->_max_hit_point : 0;
	this->_energy_point += amount;
	this->_energy_point > this->_max_energy_point ? this->_energy_point = this->_max_energy_point : 0;
	std::cout << "CL4P-TP " << this->_name
	<< " heals himself and regains its energy, of " << amount
	<< " and now he has " << this->_hit_point << " life point and "
	<< this->_energy_point << " energy." << std::endl;
	std::cout << " - [" << this->_name
	<< "] \"Health! Eww, what flavor is red?\"" << std::endl;
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}
