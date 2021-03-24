#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent		event;
	Zombie			*Olivia;

	event.setZombieType("fast");
	Olivia = event.newZombie("Olivia");
	delete Olivia;

	Zombie Random = event.randomChump();
	return (0);
}
