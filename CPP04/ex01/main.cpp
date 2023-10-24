#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const int nbOfAnimals = 4;
		Animal *array[nbOfAnimals] = {
			new Dog(),
			new Dog(),
			new Cat(),
			new Cat()};
		for (size_t i = 0; i < nbOfAnimals; i++)
			delete array[i];
		std::cout << std::endl;
	}
	{
		const Animal *a = new Dog();
		const Animal *b = new Cat();

		delete a;
		delete b;
		std::cout << std::endl;
	}
	return 0;
}