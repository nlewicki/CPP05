/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:19:49 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/11 12:34:38 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors
Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const Form &cother) : _name(cother._name), _signed(cother._signed), _gradeToSign(cother._gradeToSign), _gradeToExecute(cother._gradeToExecute)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

//Operator "=" Overload
Form &Form::operator=(const Form &cother)
{
	if (this == &cother)
		return (*this);
	_signed = cother._signed;
	return (*this);
}

//Destructor
Form::~Form()
{
}

//Getters
std::string const &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signed)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

//Exceptions
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

std::ostream	&operator<<(std::ostream &out, const Form &rhs)
{
	out << rhs.getName() << " form is ";
	if (rhs.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed";
	return (out);
}
