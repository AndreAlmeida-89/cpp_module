#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}

void BitcoinExchange::calculateBTCAmoutByDate(const std::string &inputFileName)
{
	try
	{
		Map dataBase = _parseData(_dataBaseFileName, ", ");
		Map inputData = _parseData(inputFileName, " |");
		Map::const_iterator it = inputData.begin();

		while (it != inputData.end())
		{
			float ammount = it->second;
			if (ammount < 0.0f)
				std::cout << "Error: not a positive number." << std::endl;
			else if (ammount > 1000.0f)
				std::cout << "Error: too large a number." << std::endl;
			else
			{
				time_t time = it->first;
				float value = _findValueByDate(dataBase, time);
				std::cout << _timeToString(time) << " => " << ammount << " = " << value * ammount << std::endl;
			}
			it++;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

// Operators
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void)assign;
	return *this;
}

const BitcoinExchange::Map BitcoinExchange::_parseData(const std::string &fileName,
													   const std::string &separator)
{
	std::ifstream file(fileName.c_str());
	if (file.is_open())
	{
		Map map = Map();
		std::string line;
		getline(file, line);
		while (getline(file, line))
		{
			tm date;
			float value;
			char *next = strptime(line.c_str(), ("%Y-%m-%d" + separator).c_str(), &date);
			time_t time = mktime(&date);
			if (next && sscanf(next, "%f", &value) == 1)
				map.insert(std::make_pair(time, value));
		}
		file.close();
		return map;
	}
	throw UnableToOpenFile();
}

float BitcoinExchange::_findValueByDate(BitcoinExchange::Map &map, time_t key)
{
	Map::iterator it = map.find(key);
	if (it != map.end())
		return it->second;
	else
	{
		it = map.lower_bound(key);
		if (it == map.begin())
			return 0.0;
		else
		{
			--it;
			return it->second;
		}
	}
}

std::string BitcoinExchange::_timeToString(std::time_t time)
{
	struct tm *timeinfo;
	char buffer[80];

	timeinfo = localtime(&time);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
	return std::string(buffer);
}

const char *BitcoinExchange::UnableToOpenFile::what() const throw()
{
	return "Error: could not open file.";
}

const char *BitcoinExchange::InvalidInputValue::what() const throw()
{
	return "[!] Invalid input value.";
}

const std::string BitcoinExchange::_dataBaseFileName = "data.csv";
