#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap {

protected:
	int				_hit_point;
	int				_max_hit_point;
	int				_energy_point;
	int				_max_energy_point;
	int				_level;
	std::string		_name;
	int				_melee_attack_dmg;
	int				_ranged_attack_dmg;
	int				_armor_dmg_reduction;
public:
	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &c);
	ClapTrap		&operator=(const ClapTrap &c);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void);
};

#endif
