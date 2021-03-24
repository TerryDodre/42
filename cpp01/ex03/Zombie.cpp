#include "Zombie.hpp"

void		Zombie::advert(void)
{
	std::cout << this->_name << " " << this->_type << " Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::Zombie(void)
{
    int				rand_name;
	int				rand_type;
	std::string		random_name[8] = {"Edward", "Franck", "Sacha", "Leonel", 
						"Elise", "Julia", "Celestina", "Mandy"};
	std::string		random_type[4] = {"fast", "stupid", "tall", "blue"};

	rand_name = std::rand() % 8;
	rand_type = std::rand() % 4;
    this->_name = random_name[rand_name];
    this->_type = random_type[rand_type];
}

Zombie::~Zombie()
{
}
