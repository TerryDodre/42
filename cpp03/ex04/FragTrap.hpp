#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {

public:
	FragTrap(void);
	FragTrap(int i);
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(const FragTrap &f);
	FragTrap	&operator=(const FragTrap &f);
	void		rangedAttack(std::string const &target);
	void		meleeAttack(std::string const &target);
	void		vaulthunter_dot_exe(std::string const &target);
};

#endif
