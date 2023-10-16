#include "Span.hpp"

void mainTest(void)
{
	std::cout << HMAG "[                     Main Test                     ]" reset << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	try
	{
		sp.addNumber(-11);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp.addNumber(21);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void fillListOfNumbers(void) {
	std::cout << HMAG "[                     Fill List Test                     ]" reset << std::endl;
	std::vector<int> v1;
	v1.push_back(11);
	v1.push_back(2);
	v1.push_back(45);
	v1.push_back(12);
	v1.push_back(7);
	Span sp(20);
	sp.addNumber(v1.begin(), v1.end());
	std::cout << sp << std::endl;
}

void	emptySpan() {
	std::cout << HMAG "[                     Empty Span Test                     ]" reset << std::endl;
	Span sp(2);
	try {
		sp.longestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	OnlyOneValueOnSpan() {
	std::cout << HMAG "[                     Only One Value On Span Test                     ]" reset << std::endl;
	Span sp(2);
	sp.addNumber(20);
	try {
		sp.longestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void tenMillions(void) {
	std::cout << HMAG "[                     Ten Millions Test                     ]" reset << std::endl;
	std::vector<int> v1;
	for (int i = 0; i < 10000; i++) {
		int seed = 3;
		if (i % 2 == 0)
			v1.push_back(i * seed);
		else
			v1.push_back(i / seed);
	}
	Span sp(10100);
	sp.addNumber(v1.begin(), v1.end());
	std::cout << sp << std::endl;
}

void sizeZero() {
	std::cout << HMAG "[                     size Zero Test                     ]" reset << std::endl;
	Span	sp(0);
	try {
		sp.addNumber(20);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		sp.longestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	mainTest();
	fillListOfNumbers();
	emptySpan();
	OnlyOneValueOnSpan();
	sizeZero();
	// tenMillions();
	return 0;
}