
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	struct FormType
	{
		std::string	formName;
		AForm*		(*create)(std::string);
	};

	FormType forms[3] = 
	{
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cout << "Error: form '" << name << "' doesn't exist." << std::endl;
	return NULL;
}