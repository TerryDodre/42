#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: _hit_point(100), _max_hit_point(100), _energy_point(100),
		_max_energy_point(100), _level(1), _name("Default"),
		_melee_attack_dmg(30), _ranged_attack_dmg(20), _armor_dmg_reduction(5)
{
	srand(time(0));
	std::cout << "A new Claptrap is coming, his name is " 
	<< this->_name << "." << std::endl;
	return;
}

FragTrap::FragTrap(std::string name)
	: _hit_point(100), _max_hit_point(100), _energy_point(100),
		_max_energy_point(100), _level(1), _name(name),
		_melee_attack_dmg(30), _ranged_attack_dmg(20), _armor_dmg_reduction(5)
{
	srand(time(0));
	std::cout << "A new Claptrap is coming, his name is " 
	<< this->_name << "." << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "What is he doing ?!? " << this->_name 
	<< " is running with a bomb in his arms. BOOUMM !!!" << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &f)
{
	*this = f;
	std::cout << this->_name << " has just been copied." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &f)
{
	if (this == &f)
		return (*this);
	this->_hit_point = f._hit_point;
	this->_max_hit_point = f._max_hit_point;
	this->_energy_point = f._energy_point;
	this->_max_energy_point = f._max_energy_point;
	this->_level = f._level;
	this->_name = f._name;
	this->_melee_attack_dmg = f._melee_attack_dmg;
	this->_ranged_attack_dmg = f._ranged_attack_dmg;
	this->_armor_dmg_reduction = f._armor_dmg_reduction;
	return (*this);
}

void		FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
	<< " at range, causing " << this->_ranged_attack_dmg
	<< " points of damage!" << std::endl;
}

void		FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
	<< " at melee, causing " << this->_melee_attack_dmg
	<< " points of damage!" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	int		damage;

	damage = amount - this->_armor_dmg_reduction;
	damage < 0 ? damage = 0 : 0;
	this->_hit_point -= damage;
	this->_hit_point < 0 ? this->_hit_point = 0 : 0;
	std::cout << "FR4G-TP " << this->_name << " take " << damage
	<< " points of damage! Now he has " << this->_hit_point
	<< " life point."<< std::endl;
	if (damage > 0)
	{
		std::cout << " - [" << this->_name
		<< "] \"My robotic flesh! AAHH!\"" << std::endl;
	}
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->_hit_point += amount;
	this->_hit_point > this->_max_hit_point ? this->_hit_point = 100 : 0;
	this->_energy_point += amount;
	this->_energy_point > this->_max_energy_point ? this->_energy_point = 100 : 0;
	std::cout << "FR4G-TP " << this->_name 
	<< " heals himself and regains its energy, of " << amount
	<< " and now he has " << this->_hit_point << " life point and "
	<< this->_energy_point << " energy." << std::endl;
	std::cout << " - [" << this->_name
	<< "] \"Health! Eww, what flavor is red?\"" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int				rand;
	std::string		random_pack[5] = {"Meat Unicycle",
						"Clap-In-The-Box",
						"Torgue Fiesta",
						"Pirate Ship Mode",
						"One Shot Wonder"};
	std::string		random_str[5] = {"I AM ON FIRE!!! OH GOD, PUT ME OUT!!!",
						"Gotta blow up a bad guy, GOTTA BLOW UP A BAD GUY!",
						"It's time for my free grenade giveaway!",
						"Is this really canon?",
						"Kill, reload! Kill, reload! KILL! RELOAD!"};

	if (this->_energy_point < 25)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " does nothing because it has no more energy." << std::endl;
		std::cout << " - [" << this->_name
		<< "] \"Times like these, I really start to question the meaning "
		<< "of my existence. Then I get distra-hey! What's this? This "
		<< "looks cool!\"" << std::endl;
		return ;
	}
	this->_energy_point -= 25;
	this->_energy_point < 0 ? this->_energy_point = 0 : 0;
	rand = std::rand() % 5;
	std::cout << "FR4G-TP " << this->_name << " load the action pack : "
	<< random_pack[rand] << "!!!" << std::endl;
	if (rand < 2)
	{
		std::cout << " - [" << this->_name << "] \"" << random_str[rand]
		<< "\"" << std::endl;
		meleeAttack(target);
	}
	else
	{
		std::cout << " - [" << this->_name << "] " << random_str[rand]
		<< "\"" << std::endl;
		rangedAttack(target);
	}
}
