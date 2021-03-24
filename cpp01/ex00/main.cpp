#include "Pony.hpp"

void		ponyOnTheStack(void)
{
	std::cout << "A new wild pony appears on the stack." << std::endl;
	Pony	speedy("Speedy", "Brown", "1m49");
}

void		ponyOnTheHeap(void)
{
	std::cout << "A new wild pony appears on the heap." << std::endl;
	Pony	*buzzy = new Pony("Buzzy", "Black", "1m47");
	delete buzzy;
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
