/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:19 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 13:30:11 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		//Constructors
		Intern();
		Intern(const Intern &cother);

		//Destructor
		~Intern();

		//Operator "=" Overload
		Intern	&operator=(const Intern &cother);

		//Methods
		AForm	*makeForm(std::string const &name, std::string const &target);
};

#endif
