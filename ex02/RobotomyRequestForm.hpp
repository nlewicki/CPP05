/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:00 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/12 13:00:47 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		//Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &cother);

		//Destructor
		~RobotomyRequestForm();

		//Operator "=" Overload
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &cother);

		//Getters
		std::string	const	&getTarget() const;

		//Methods
		void	execute(Bureaucrat const &executor) const;
};

#endif
