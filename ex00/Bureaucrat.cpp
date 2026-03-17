/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:03:05 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/17 12:03:07 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(other._name), _grade(other._grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{

}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{

}


Bureaucrat::~Bureaucrat()
{
}