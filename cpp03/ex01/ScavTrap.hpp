#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class	ScavTrap {

private:
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
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &s);
	ScavTrap		&operator=(const ScavTrap &s);
	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			challengeNewcomer(void);
};

#endif
