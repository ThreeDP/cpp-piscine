#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "define.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	std::srand(std::time(0));
    int randNum = std::rand() % 3;
    switch (randNum) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << MAGHB << std::setw(10) << "A" reset << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << MAGHB << std::setw(10) << "B" reset << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << MAGHB << std::setw(10) << "C" reset << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << YELHB << std::setw(10) << "A" reset << std::endl;
		(void)a;
	} catch (const std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << YELHB << std::setw(10) << "B" reset << std::endl;
			(void)b;
		} catch (const std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << YELHB << std::setw(10) << "C" reset << std::endl;
				(void)c;
			} catch (const std::exception &e) {
				std::cout << REDHB "[ this is a bad thing ]" reset << std::endl;
			} 
		}
	}
}

int main() {
	Base *b1 = generate();
	Base *b2 = generate();
	Base *b3 = generate();
	Base *b4 = generate();

	identify(*b1);
	identify(b2);
	identify(*b3);
	identify(b4);

	delete b1;
	delete b2;
	delete b3;
	delete b4;
}