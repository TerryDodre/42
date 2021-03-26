#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class	SuperTrap : public NinjaTrap, public FragTrap {

public:
	SuperTrap(void);
	SuperTrap(std::string name);
	~SuperTrap(void);
	SuperTrap(SuperTrap const &s);
	SuperTrap	&operator=(SuperTrap const &s);
	void		rangedAttack(std::string target);
	void		meleeAttack(std::string target);
};

#endif
