#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for (size_t i = 0; i < 4; i++)
		delete array[i];
	return 0;
}