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

// Operators
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void)assign;
	return *this;
}

void BitcoinExchange::calculate(const std::string &inputFileName)
{
	try
	{
		Map dataBase = _parseDataBase();
		std::ifstream file(inputFileName.c_str());
		if (file.is_open())
		{
			Map map = Map();
			std::string line;
			getline(file, line);
			while (getline(file, line))
			{
				tm date;
				float ammount;
				memset(&date, 0, sizeof(date));
				char *next = strptime(line.c_str(), "%Y-%m-%d | ", &date);
				time_t time = mktime(&date);
				if (!next || time == -1 || sscanf(next, "%f", &ammount) != 1)
				{
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
				}
				if (ammount < 0.0f)
					std::cout << "Error: not a positive number." << std::endl;
				else if (ammount > 1000.0f)
					std::cout << "Error: too large a number." << std::endl;
				else
					std::cout << _timeToString(time) << " => " << ammount << " = " << ammount * _findValueByDate(dataBase, time) << std::endl;
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

const BitcoinExchange::Map BitcoinExchange::_parseDataBase()
{
	std::ifstream file(_dataBaseFileName.c_str());
	if (file.is_open())
	{
		Map map = Map();
		std::string line;
		getline(file, line);
		while (getline(file, line))
		{
			tm date;
			float value;
			memset(&date, 0, sizeof(date));
			char *next = strptime(line.c_str(), "%Y-%m-%d,", &date);
			time_t time = mktime(&date);
			if (next && sscanf(next, "%f", &value) == 1)
				map[time] = value;
			else
				map[time] = 0.0f;
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
			return 0.0f;
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

const std::string BitcoinExchange::_dataBaseFileName = "data.csv";
