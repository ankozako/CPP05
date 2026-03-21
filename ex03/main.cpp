/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:11:47 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/20 14:11:48 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someIntern;

	std::cout << "--- Test 1: Create shrubbery creation form ---" << std::endl;
	try
	{
		AForm* f = someIntern.makeForm("shrubbery creation", "garden");
		if (f)
		{
			std::cout << *f << std::endl;
			delete f;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Create robotomy request form ---" << std::endl;
	try
	{
		AForm* f = someIntern.makeForm("robotomy request", "Bender");
		if (f)
		{
			std::cout << *f << std::endl;
			delete f;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Create presidential pardon form ---" << std::endl;
	try
	{
		AForm* f = someIntern.makeForm("presidential pardon", "Zaphod");
		if (f)
		{
			std::cout << *f << std::endl;
			delete f;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Unknown form name ---" << std::endl;
	try
	{
		AForm* f = someIntern.makeForm("shredding request", "Bender");
		if (f)
		{
			std::cout << *f << std::endl;
			delete f;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Full workflow ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		AForm* f = someIntern.makeForm("robotomy request", "Bender");
		if (f)
		{
			boss.signForm(*f);
			boss.executeForm(*f);
			delete f;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}