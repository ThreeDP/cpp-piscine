#include "Serializer.hpp"

int main() {
	Data a = (Data){.camel= 10, .crystal= 'c'};
	Data *d = &a;
	uintptr_t ptr = Serializer::serialize(d);
	Data *res = Serializer::deserialize(ptr);
	if (d != res) {
		std::cout << REDHB "[ WRONG!! ]" reset << std::endl;
	} else 
		std::cout << GRNHB "[ OK! ]" reset << std::endl;
}