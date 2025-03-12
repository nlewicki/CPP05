/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:09:51 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 12:59:22 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));
	Bureaucrat b1("Lazy John", 137);
	Bureaucrat b2("Hardworking John", 45);
	Bureaucrat b3("Nepo Baby", 5);
	ShrubberyCreationForm f1("home");
	RobotomyRequestForm f2("Lazy John");
	PresidentialPardonForm f3("Lazy John");

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	b1.signForm(f1);
	b1.executeForm(f1);
	b1.signForm(f2);
	b2.signForm(f2);
	b2.executeForm(f2);
	b3.signForm(f3);
	b3.executeForm(f3);
	return(0);
}
