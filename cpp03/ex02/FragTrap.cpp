#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_point = 100;
	this->_max_hit_point = 100;
	this->_energy_point = 100;
	this->_max_energy_point = 100;
	this->_level = 1;
	this->_name = "Defautl";
	this->_melee_attack_dmg = 30;
	this->_ranged_attack_dmg = 20;
	this->_armor_dmg_reduction = 5;
	srand(time(0));
	std::cout << "A new Claptrap is coming, his name is "<< this->_name 
	<< "." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	this->_hit_point = 100;
	this->_max_hit_point = 100;
	this->_energy_point = 100;
	this->_max_energy_point = 100;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_dmg = 30;
	this->_ranged_attack_dmg = 20;
	this->_armor_dmg_reduction = 5;
	srand(time(0));
	std::cout << "A new Claptrap is coming, his name is "<< this->_name 
	<< "." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "What is he doing ?!? " << this->_name
	<< " is running with a bomb in his arms. BOOUMM !!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
	*this = f;
	std::cout << this->_name << " has just been copied." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &f)
{
	if (this == &f)
		return (*this);
	ClapTrap::operator=(f);
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
