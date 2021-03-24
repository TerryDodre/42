#include "ZombieHorde.hpp"

void		ZombieHorde::announce()
{
	while (_nb_zombie > 0)
		_hordes[--_nb_zombie].advert();
}

ZombieHorde::ZombieHorde(int n)
{
	srand(time(0));
	_hordes = new Zombie[n];
	_nb_zombie = n;
	announce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] _hordes;
	std::cout << "The horde is destroyed." << std::endl;
}
