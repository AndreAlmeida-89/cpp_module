#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <fstream>
#include <iomanip>
#include <cstring>

class BitcoinExchange
{
public:
	// Destructor
	~BitcoinExchange();

	static void calculate(const std::string &inputFileName);

	// Exceptions
	class UnableToOpenFile : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	// Type definitions
	typedef std::map<time_t, float> Map;

	// Constructors
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &assign);

	// Static functions
	static const std::string _dataBaseFileName;
	static const BitcoinExchange::Map _parseDataBase();
	static float _findValueByDate(BitcoinExchange::Map &myMap, time_t key);
	static std::string _timeToString(std::time_t time);
};

#endif