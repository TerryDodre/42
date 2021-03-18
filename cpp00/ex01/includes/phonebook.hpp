#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "contact.hpp"

class phonebook {

private:
	contact		page[8];
	int			contact_number;

public:
	phonebook(void);
	~phonebook(void);
	int			add_contact();
	int			search_contact();
	void		ini();
};

#endif
