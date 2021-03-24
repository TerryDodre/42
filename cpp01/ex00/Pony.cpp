#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string size)
	: _name(name), _color(color), _size(size)
{
	std::cout << "His name is " << _name << ", his coat color is "
	<< _color << " and he measures " << _size << "." << std::endl;
}

Pony::~Pony(void)
{
	std::cout << _name << " fled." << std::endl;
}
