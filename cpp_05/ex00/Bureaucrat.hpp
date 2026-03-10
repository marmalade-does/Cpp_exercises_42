/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:07:34 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 12:08:25 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	
	~Bureaucrat();	

	const std::string &getName(void) const;
	int getGrade(void) const;
	
	int incrementGrade(void);
	int decrementGrade(void);
	
	class GradeTooHighException; // chat gave this, idk how to use it
	class GradeTooLowException; // chat gave this, idk how to use it

private:
	std::string	_name;
	int			_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */
