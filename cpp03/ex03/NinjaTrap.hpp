#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class	NinjaTrap : public ClapTrap {

public:
    NinjaTrap(void);
	NinjaTrap(std::string name);
	~NinjaTrap(void);
    NinjaTrap(const NinjaTrap &n);
    NinjaTrap       &operator=(const NinjaTrap &n);
    void		    rangedAttack(std::string const &target);
    void		    meleeAttack(std::string const &target);
    void            ninjaShoebox(NinjaTrap &Ctrap);
    void            ninjaShoebox(FragTrap &Ctrap);
    void            ninjaShoebox(ScavTrap &Ctrap);
    void            ninjaShoebox(ClapTrap &Ctrap);
};

#endif
