#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class   Human{
private:
	const Brain		_brain;

public:
	std::string		identify() const;
	const Brain		&getBrain() const;
};

#endif
