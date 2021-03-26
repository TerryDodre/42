#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class	FragTrap {

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
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(const FragTrap &f);
	FragTrap		&operator=(const FragTrap &f);
	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const &target);
};

#endif
