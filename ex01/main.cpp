#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	w1("woosekim_1", 1);
		Bureaucrat	b20("b_20", 20);

		Form		f2("f_2", 2, 2);
		Form		f5("f_5", 5, 5);
		Form		copy(f2);

		std::cout << w1;
		std::cout << b20;
		std::cout << f2;
		std::cout << f5;
		std::cout << copy;
		
		f2.beSigned(w1);
		std::cout << f2;
		// f5.BeSigned(b20);
		std::cout << f5;

		std::cout << copy;

		copy = f5;
		std::cout << copy;

		b20.signForm(f5);
		std::cout << f5;
		w1.signForm(f5);
		std::cout << f5;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}