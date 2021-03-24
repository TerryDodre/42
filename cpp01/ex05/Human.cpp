#include "Human.hpp"

std::string			Human::identify(void) const
{
	return	(this->getBrain().identify());
}

const Brain			&Human::getBrain(void) const
{
	return (this->_brain);
}
