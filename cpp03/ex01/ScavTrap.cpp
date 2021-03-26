#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: _hit_point(100), _max_hit_point(100), _energy_point(50),
		_max_energy_point(50), _level(1), _name("Default"),
		_melee_attack_dmg(20), _ranged_attack_dmg(15), _armor_dmg_reduction(3)
{
	srand(time(0));
	std::cout << "Hello! I am your new steward bot, my name is "
	<< this->_name << "." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name)
	: _hit_point(100), _max_hit_point(100), _energy_point(50),
		_max_energy_point(50), _level(1), _name(name),
		_melee_attack_dmg(20), _ranged_attack_dmg(15), _armor_dmg_reduction(3)
{
	srand(time(0));
	std::cout << "Hello! I am your new steward bot, my name is "
	<< this->_name << "." << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "What ?!? " << this->_name << " destroyed himself."
	<< std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	*this = s;
	std::cout << this->_name << " has just been copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &s)
{
	if (this == &s)
		return (*this);
	this->_hit_point = s._hit_point;
	this->_max_hit_point = s._max_hit_point;
	this->_energy_point = s._energy_point;
	this->_max_energy_point = s._max_energy_point;
	this->_level = s._level;
	this->_name = s._name;
	this->_melee_attack_dmg = s._melee_attack_dmg;
	this->_ranged_attack_dmg = s._ranged_attack_dmg;
	this->_armor_dmg_reduction = s._armor_dmg_reduction;
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

void		ScavTrap::takeDamage(unsigned int amount)
{
	int		damage;

	damage = amount - this->_armor_dmg_reduction;
	damage < 0 ? damage = 0 : 0;
	this->_hit_point -= damage;
	this->_hit_point < 0 ? this->_hit_point = 0 : 0;
	std::cout << "SCAV-TP " << this->_name << " take " << damage 
	<< " points of damage! Now he has " << this->_hit_point
	<< " life point."<< std::endl;
	if (damage > 0)
		std::cout << " - [" << this->_name << "] \"I'm leaking!\"" << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	this->_hit_point += amount;
	this->_hit_point > this->_max_hit_point ? this->_hit_point = 100 : 0;
	this->_energy_point += amount;
	this->_energy_point > this->_max_energy_point ? this->_energy_point = 50 : 0;
	std::cout << "SCAV-TP " << this->_name
	<< " heals himself and regains its energy, of  " << amount
	<< " and now he has " << this->_hit_point << " life point and "
	<< this->_energy_point << " energy." << std::endl;
	std::cout << " - [" << this->_name << "] \"Sweet life juice!\"" << std::endl;
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
