/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:03:52 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 13:07:52 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		//Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cother);

		//Destructor
		~ShrubberyCreationForm();

		//Operator "=" Overload
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &cother);

		//Getters
		std::string	const	&getTarget() const;

		//Methods
		void	execute(Bureaucrat const &executor) const;
};

#endif
