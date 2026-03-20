/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:12:05 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/20 14:12:06 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);	
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string	getName() const;
		bool		getIsSigned() const;	
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		void		beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif

