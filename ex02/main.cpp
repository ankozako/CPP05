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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "--- Test 1: Shrubbery - success ---" << std::endl;
	try
	{
		Bureaucrat b("Alice", 130);
		ShrubberyCreationForm f("garden");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Shrubbery - not signed ---" << std::endl;
	try
	{
		Bureaucrat b("Bob", 130);
		ShrubberyCreationForm f("garden");
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Shrubbery - grade too low to execute ---" << std::endl;
	try
	{
		Bureaucrat b("Charlie", 138);
		ShrubberyCreationForm f("garden");
		Bureaucrat signer("Signer", 140);
		signer.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Robotomy - success ---" << std::endl;
	try
	{
		Bureaucrat b("Dave", 40);
		RobotomyRequestForm f("Bender");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Robotomy - grade too low to sign ---" << std::endl;
	try
	{
		Bureaucrat b("Eve", 100);
		RobotomyRequestForm f("Bender");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: Presidential pardon - success ---" << std::endl;
	try
	{
		Bureaucrat b("Frank", 1);
		PresidentialPardonForm f("Zaphod");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 7: Presidential pardon - grade too low to execute ---" << std::endl;
	try
	{
		Bureaucrat b("Grace", 10);
		PresidentialPardonForm f("Zaphod");
		Bureaucrat signer("Signer", 20);
		signer.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 8: executeForm success message ---" << std::endl;
	try
	{
		Bureaucrat b("Hannah", 1);
		PresidentialPardonForm f("Ford");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
