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
	struct DateComparator;
	typedef struct tm Date;
	typedef std::multimap<time_t, float> Map;

	// Constructors
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &assign);

	// Class F
	static const std::string dataBaseFileNale;
	static const BitcoinExchange::Map _parseDataBase();
	static float _findValueByDate(BitcoinExchange::Map &myMap, time_t key);

	// Exceptions
	class UnableToOpenFile : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInputValue : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Struct
	struct DateComparator
	{
		bool operator()(const Date &lhs, const Date &rhs) const;
	};

};

#endif