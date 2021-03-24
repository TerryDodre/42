#include "HumanB.hpp"

void		HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his "<< this->_weapon->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name)
	: _name(name)
{
}

HumanB::~HumanB()
{
}
