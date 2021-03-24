#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

class replace {
private:
	std::string		filename;
	std::string		s1;
	std::string		s2;

public:
	replace(std::string file, std::string argv1, std::string argv2);
	~replace();
	int				check();
	int				replace_program();
	int				write_replace(std::string ret);
};

#endif
