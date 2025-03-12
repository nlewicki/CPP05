/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:41 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 12:59:16 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 137), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cother) : AForm(cother)
{
	if(this == &cother)
		return ;
	_target = cother._target;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

//Operator "=" Overload
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &cother)
{
	if(this == &cother)
		return (*this);
	AForm::operator=(cother);
	_target = cother._target;
	return (*this);
}

//Getters
std::string const &RobotomyRequestForm::getTarget() const
{
	return _target;
}

//Methods
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
