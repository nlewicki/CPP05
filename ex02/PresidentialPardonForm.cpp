/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFrom.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:26:31 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 12:55:56 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 25), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cother) : AForm(cother)
{
	if(this == &cother)
		return ;
	_target = cother._target;
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

//Operator "=" Overload
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &cother)
{
	if (this == &cother)
		return (*this);
	AForm::operator=(cother);
	return (*this);
}

//Getters
std::string const &PresidentialPardonForm::getTarget() const
{
	return _target;
}

//Methods
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
