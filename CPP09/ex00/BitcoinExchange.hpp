#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <fstream>
#include <iomanip>

class BitcoinExchange
{
public:
	// Destructor
	~BitcoinExchange();

	static void calculateBTCAmoutByDate(const std::string &inputFileName);

private:
	// Type definitions
	typedef std::multimap<time_t, float> Map;

	// Constructors
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &assign);

	// Class F
	static const std::string _dataBaseFileName;
	static const BitcoinExchange::Map _parseData(const std::string &fileName,
												 const std::string &separator);
	static float _findValueByDate(BitcoinExchange::Map &myMap, time_t key);
	static std::string _timeToString(std::time_t time);

	// Exceptions
	class UnableToOpenFile : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInputValue : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif