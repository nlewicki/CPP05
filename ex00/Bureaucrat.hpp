/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:27:39 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/26 10:51:53 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		void				setGrade(int grade);

	public:
	//Constructors
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &cother);

	//Destructor
		~Bureaucrat();

	//Operator "=" Overload
		Bureaucrat	&operator=(const Bureaucrat &cother);

	//Getters
		std::string const	&getName() const;
		int					getGrade() const;

	//Methods
		void				incrementGrade();
		void				decrementGrade();

	//Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
