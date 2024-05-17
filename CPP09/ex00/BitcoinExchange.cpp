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
		Map dataBase = _parseDataBase();
		std::ifstream file(inputFileName.c_str());
		if (file.is_open())
		{
			std::string line;
			getline(file, line);
			while (getline(file, line))
			{
				Date date;
				float ammount = 0;
				char dateBuffer[100];
				char *next = strptime(line.c_str(), "%Y-%m-%d |", &date);
				if (next && sscanf(next, "%f", &ammount) == 1)
				{
					if (ammount < 0.0f)
						std::cout << "Error: not a positive number." << std::endl;
					else if (ammount > 1000.0f)
						std::cout << "Error: too large a number." << std::endl;
					else
					{
						std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", &date);
						time_t time = mktime(&date);
						float value = _findValueByDate(dataBase, time);
						std::cout << std::fixed << std::setprecision(1);
						std::cout << dateBuffer << " => " << ammount << " = " << value * ammount << std::endl;
					}
				}
			}
			file.close();
		}
		else
			throw UnableToOpenFile();
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

const BitcoinExchange::Map BitcoinExchange::_parseDataBase()
{
	std::ifstream file(dataBaseFileNale.c_str());
	if (file.is_open())
	{
		Map dataBaseMap = Map();
		std::string line;
		getline(file, line);
		while (getline(file, line))
		{
			Date date;
			float value;
			char *next = strptime(line.c_str(), "%Y-%m-%d,", &date);
			if (next && sscanf(next, "%f", &value) == 1)
			{
				time_t time = mktime(&date);
				dataBaseMap.insert(std::make_pair(time, value));
			}
		}
		file.close();
		return dataBaseMap;
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

const char *BitcoinExchange::UnableToOpenFile::what() const throw()
{
	return "[!] File can not be opened.";
}

const char *BitcoinExchange::InvalidInputValue::what() const throw()
{
	return "[!] Invalid input value.";
}

bool BitcoinExchange::DateComparator::operator()(const Date &lhs, const Date &rhs) const
{
	return mktime(const_cast<Date *>(&lhs)) < mktime(const_cast<Date *>(&rhs));
}

const std::string BitcoinExchange::dataBaseFileNale = "data.csv";
