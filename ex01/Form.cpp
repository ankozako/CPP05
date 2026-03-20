/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:58:05 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/20 10:58:07 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{

}


Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}


Form::~Form()
{
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const	
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() 
	<< ", signed: " << f.getIsSigned()
	<< ", grade to sign: " << f.getGradeToSign()
	<< ", grade to exec: " << f.getGradeToExec() << ".";
	
	return out;
}
