/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:26:45 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 12:54:57 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
	//Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &cother);

	//Destructor
		~PresidentialPardonForm();

	//Operator "=" Overload
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &cother);

	//Getters
		std::string	const	&getTarget() const;

	//Methods
		void	execute(Bureaucrat const &executor) const;
};

#endif
