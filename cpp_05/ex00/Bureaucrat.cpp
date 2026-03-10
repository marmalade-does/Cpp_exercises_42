/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:18:58 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 12:09:38 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.';
	return out;
}

#endif /* BUREAUCRAT_HPP */


Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat spawned" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat slain" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_name = bureaucrat._name;
		_grade = bureaucrat._grade;
	}
	return *this;
}

// ------------------------

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

int Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1 || _grade > 150)
		// throw error
	else
		_grade++;
}

int Bureaucrat::decrementGrade(void)
{
	if (_grade < 1 || _grade >= 150)
		// throw error
	else
		_grade--;
}

