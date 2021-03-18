#include "../includes/phonebook.hpp"

phonebook::phonebook(void)
{
	contact_number = 0;
}

phonebook::~phonebook(void)
{
}

void	board(std::string str)
{
	int		i = str.length();

	std::cout << "|";
	if (str.length() > 10)
		std::cout << str.substr(0,9) << ".";
	else
		std::cout << std::setw(10 - i) << "" << str;
}

int		phonebook::search_contact(void)
{
	std::string		request;
	int				index;
	int				i = 0;

	if (contact_number == 0)
		std::cout << "Sorry the phonebook is empty." << std::endl;
	else
	{
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|     LOGIN|" << std::endl;
		while (i < contact_number)
		{
			board(std::to_string(i));
			board(page[i].get("first_name"));
			board(page[i].get("last_name"));
			board(page[i].get("login"));
			std::cout << "|";
			std::cout << std::endl;
			i++;
		}
		i = 0;
		std::cout << std::endl << "Write the index you want : ";
		std::getline(std::cin, request);
		if (std::cin.eof())
			return (3);
		while (request[i] && request[i] >= '0' && request[i] <= '9')
			i++;
		index = std::atoi(request.c_str());
		if (index < 0 || index >= contact_number || i != request.length())
			std::cout << "Sorry, this profile does not exist." << std::endl;
		else
			page[index].get_page();
	}
	return (0);
}

int		phonebook::add_contact(void)
{
	if (contact_number > 7)
		std::cout << "The phonebook is full sorry." << std::endl;
	else
	{
		page[contact_number] = contact();
		page[contact_number].add();
		contact_number++;
	}
	if (std::cin.eof())
		return (3);
	return (0);
}

int		wait_menu(void)
{
	std::string		request;

	std::cout << "Tell me, what do you want, ADD, SEARCH or EXIT ? " << std::endl;
	std::getline(std::cin, request);
	if (std::cin.eof())
		return (3);
	else if (request == "ADD")
		return (1);
	else if (request == "SEARCH")
		return (2);
	else if (request == "EXIT")
		return (3);
	return (0);
}

int		main(void)
{
	phonebook		pb = phonebook();
	int				cmd = 0;

	std::cout << "Hello, i'm your PhoneBook." << std::endl;
	while (1)
	{
		if (cmd == 0)
			cmd = wait_menu();
		else if (cmd == 1)
			cmd = pb.add_contact();
		else if (cmd == 2)
			cmd = pb.search_contact();
		else if (cmd == 3)
			break ;
	}
	std::cout << "\nGoodbye." << std::endl;
	return (0);
}
