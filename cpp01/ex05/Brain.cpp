#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

std::string			Brain::identify(void) const
{
	std::stringstream	adress;

	adress << this;
	return (adress.str());
}
