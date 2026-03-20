/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:02:36 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/17 12:02:38 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "--- Test 1: Valid Form construction ---" << std::endl;
	try
	{
		Form f("TaxForm", 50, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Form grade too high ---" << std::endl;
	try
	{
		Form f("TaxForm", 0, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Form grade too low ---" << std::endl;
	try
	{
		Form f("TaxForm", 50, 151);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Bureaucrat signs form successfully ---" << std::endl;
	try
	{
		Bureaucrat b("Hannah", 30);
		Form f("TaxForm", 50, 25);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Bureaucrat grade too low to sign ---" << std::endl;
	try
	{
		Bureaucrat b("Ivan", 100);
		Form f("TaxForm", 50, 25);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}