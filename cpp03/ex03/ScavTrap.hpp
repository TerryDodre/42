#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &s);
	ScavTrap		&operator=(const ScavTrap &s);
	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			challengeNewcomer();
};

#endif
