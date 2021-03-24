#include "Zombie.hpp"

void		Zombie::advert(void)
{
	std::cout << this->_name << " " << this->_type << " Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::Zombie(std::string name, std::string type)
	: _name(name), _type(type)
{
	advert();
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead." << std::endl;
}
