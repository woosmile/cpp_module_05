#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	b150("b_150", 150);
		Bureaucrat	w1("woosekim_1", 1);
		Bureaucrat	copy(w1);

		std::cout << b150;
		std::cout << w1;
		std::cout << copy;

		// b150.DecGrade();
		w1.decGrade();
		copy.decGrade();

		std::cout << b150;
		std::cout << w1;
		std::cout << copy;

		w1.incGrade();
		// b150.DecGrade();
		copy.decGrade();

		std::cout << b150;
		std::cout << w1;
		std::cout << copy;

		copy = b150;

		std::cout << copy;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}