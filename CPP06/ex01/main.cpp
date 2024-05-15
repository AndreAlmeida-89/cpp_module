#include "Serializer.hpp"

int main()
{
	// Create a Data object
	Data data = Data("Hello from 42 Rio!");

	// Serialize the Data object
	uintptr_t serialized = Serializer::serialize(&data);

	// Deserialize the uintptr_t
	Data *deserialized = Serializer::deserialize(serialized);

	// Check if the deserialized pointer is equal to the original pointer
	if (deserialized == &data)
	{
		std::cout << "The deserialized pointer is equal to the original pointer." << std::endl
				  << "Content: " << deserialized->getContent() << std::endl;
	}
	else
	{
		std::cout << "The deserialized pointer is not equal to the original pointer." << std::endl;
	}

	return 0;
}