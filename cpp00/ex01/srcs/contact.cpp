#include "../includes/contact.hpp"

std::string	contact::get(std::string str)
{
	if (str == "first_name")
		return (first_name);
	else if (str == "last_name")
		return (last_name);
	else if (str == "login")
		return (login);
	else
		return (NULL);
}

void		contact::get_page(void)
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << login << std::endl;
	std::cout << postal_address << std::endl;
	std::cout << email_address << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << birthday_date << std::endl;
	std::cout << favorite_meal << std::endl;
	std::cout << underwear_color << std::endl;
	std::cout << darkest_secret << std::endl;
	std::cout << std::endl;
}

void		contact::add(void)
{
	std::cout << "Please fill in this information." << std::endl;
	std::cout << "First Name : ";
	std::getline (std::cin,first_name);
	std::cout << "Last Name : ";
	std::getline (std::cin,last_name);
	std::cout << "Nickname : ";
	std::getline (std::cin,nickname);
	std::cout << "Login : ";
	std::getline (std::cin,login);
	std::cout << "Postal Address : ";
	std::getline (std::cin,postal_address);
	std::cout << "Email Address : ";
	std::getline (std::cin,email_address);
	std::cout << "Phone Number : ";
	std::getline (std::cin,phone_number);
	std::cout << "Birthday Date : ";
	std::getline (std::cin,birthday_date);
	std::cout << "Favorite Meal : ";
	std::getline (std::cin,favorite_meal);
	std::cout << "Underwear Color : ";
	std::getline (std::cin,underwear_color);
	std::cout << "Darkest Secret : ";
	std::getline (std::cin,darkest_secret);
	std::cout << std::endl;
}
