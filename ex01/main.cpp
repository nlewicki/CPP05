/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:09:51 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/11 12:10:09 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("Lazy John", 150);
	Bureaucrat b2("Exemplary Billy", 1);
	Bureaucrat b3("Average Joe", 75);
	Form f1("Form1", 1, 1);
	Form f2("Form2", 150, 150);
	Form f3("Form3", 75, 75);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	b1.signForm(f1);
	b2.signForm(f2);
	b3.signForm(f3);
	b3.signForm(f1);
	b1.signForm(f3);
	b2.signForm(f1);
	return(0);
}
