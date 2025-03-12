/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:19:49 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/11 13:18:58 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors
AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const AForm &cother) : _name(cother._name), _signed(cother._signed), _gradeToSign(cother._gradeToSign), _gradeToExecute(cother._gradeToExecute)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

//Operator "=" Overload
AForm &AForm::operator=(const AForm &cother)
{
	if (this == &cother)
		return (*this);
	_signed = cother._signed;
	return (*this);
}

//Destructor
AForm::~AForm()
{
}

//Getters
std::string const &AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signed)
		throw AForm::AlreadySignedException();
	else if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(_signed == false)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

//Exceptions
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("AForm is already signed");
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream	&operator<<(std::ostream &out, const AForm &rhs)
{
	out << rhs.getName() << " AForm is ";
	if (rhs.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed";
	return (out);
}
