#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony {

private:
	std::string	_name;
	std::string	_color;
	std::string	_size;

public:
	Pony(std::string name, std::string color, std::string size);
	~Pony(void);
};

#endif
