/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:31 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 13:38:36 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Constructors
Intern::Intern()
{
}

Intern::Intern(const Intern &cother)
{
	*this = cother;
}

//Destructor
Intern::~Intern()
{
}

//Operator "=" Overload
Intern	&Intern::operator=(const Intern &cother)
{
	if (this == &cother)
		return (*this);
	return (*this);
}

//Methods
typedef AForm* (*FormCreator)(std::string const&);

// Individual functions for creating forms
static AForm* createShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	// Array of known forms
	struct FormPair
	{
		std::string name;
		FormCreator creator;
	};

	FormPair formList[] =
	{
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request", createRobotomy },
		{ "presidential pardon", createPardon }
	};

	// Iterate over the array to find the correct form
	for (int i = 0; i < 3; i++)
	{
		if (formList[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formList[i].creator(target);
		}
	}

	std::cerr << "Error: Form '" << name << "' does not exist!" << std::endl;
	return nullptr;
}
