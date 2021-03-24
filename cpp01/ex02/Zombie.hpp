#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie {

private:
	std::string	_name;
	std::string	_type;

public:
	Zombie(std::string name, std::string type);
	~Zombie();
	void	advert();
};

#endif
