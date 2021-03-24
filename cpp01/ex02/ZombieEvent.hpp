#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <cstdlib>
# include <ctime>

class	ZombieEvent {

private:
	std::string	_type;

public:
	void	setZombieType(std::string type);
	Zombie	*newZombie(std::string name);
	Zombie	randomChump();
};

#endif
