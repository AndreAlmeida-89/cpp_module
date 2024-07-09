#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const int nbOfAnimals = 4;
		AAnimal *array[nbOfAnimals] = {
			new Dog(),
			new Dog(),
			new Cat(),
			new Cat()};
		for (size_t i = 0; i < nbOfAnimals; i++)
			delete array[i];
		std::cout << std::endl;
	}
	{
		const AAnimal *a = new Dog();
		const AAnimal *b = new Cat();

		a->makeSound();
		b->makeSound();
		delete a;
		delete b;
		std::cout << std::endl;
	}
	// {
	// 	AAnimal a;
	// }
	return 0;
}