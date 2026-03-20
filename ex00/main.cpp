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

int	main()
{
	std::cout << "--- Test 1: Valid construction ---" << std::endl;
	try
	{
		Bureaucrat b("Alina", 75);
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- Test 2: Grade too high ---" << std::endl;
	try
	{
		Bureaucrat b("Barb", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "--- Test 3: Grade too low ---" << std::endl;
	try
	{
		Bureaucrat b("Charlie", 151);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- Test 4: Increment past grade 1 ---" << std::endl;
	try
	{
		Bureaucrat b("Dan", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- Test 5: Increment past grade 150 ---" << std::endl;
	try
	{
		Bureaucrat b("Ernie", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- Test 6: Valid in/decrement ---" << std::endl;
	 try
	{
		Bureaucrat b("Fiona", 50);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- Test 7: CC ---" << std::endl;
	try
	{
		Bureaucrat b1("Grace", 42);
		Bureaucrat b2(b1);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}