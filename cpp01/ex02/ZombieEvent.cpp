#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name, _type);
	return (zombie);
}

Zombie		ZombieEvent::randomChump(void)
{
	int				rand;
	std::string		random_name[8] = {"Edward", "Franck", "Sacha", "Leonel", 
						"Elise", "Julia", "Celestina", "Mandy"}; 

	srand(time(0));
	rand = std::rand() % 8;
	Zombie zombie(random_name[rand], "stupid");
	return (zombie);
}
