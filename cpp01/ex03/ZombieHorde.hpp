#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class	ZombieHorde {

private:
	Zombie		*_hordes;
	int			_nb_zombie;

public:
	ZombieHorde(int n);
	~ZombieHorde();
	void        announce();
};

#endif
