#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		//test constructors of Animal, Dog and Cat
		Animal animal;
		std::cout << animal << std::endl;
		Dog dog;
		std::cout << dog << std::endl;
		Cat cat;
		std::cout << cat << std::endl;

		// test makeSound() of Animal, Dog and Cat
		animal.makeSound();
		dog.makeSound();
		cat.makeSound();
	}
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		meta->makeSound();
		delete meta;
		delete i;
	}
	return 0;
}