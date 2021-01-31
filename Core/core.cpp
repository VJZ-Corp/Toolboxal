// core.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "core.h"

bool isNumber(const std::string& str)
{
	char* end = nullptr;
	double value = strtod(str.c_str(), &end);
	return end != str.c_str() && *end == '\0' && value != HUGE_VAL;
}

std::string Core::Radix_Converter(std::string num, int origin, int base)
{
	// filter out all whitespaces in given string
	if (!(num.find(' ') != std::string::npos))
	{
		std::fstream tempfile;
		tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::string cmd = "vendor\\python3.9_x64amd\\pythonw.exe scripts/radix.py " + num + " " + std::to_string(origin) + " " + std::to_string(base);
		std::string result;

		system(cmd.c_str()); /* invoke python interpreter through system call */ 
		std::getline(tempfile, result);

		tempfile.close();
		return result;
	}
	else
		return "Invalid string literal detected for specified radix.";
}

std::string Core::Magnitude_Converter(std::string num, int origin, int destination, RadioButtonOptions options)
{
	// filter out any string literals that are not numbers
	if (isNumber(num))
	{
		double result = 0, precision = 0;
		typedef std::numeric_limits<double> dbl;

		// format result based on locale
		std::stringstream str_stream;
		str_stream.imbue(std::locale(""));

		if (options.i_useBin) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1024^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1024, power);
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [8 * 1024^from_index / 1000^to_index]
				double deci_bin = 8 * std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using 8 * input_num * [1024^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = 8 * std::stod(num) * std::pow(1024, power);
			}
			else
			{
				// result can be calculated using input_num * [1024^from_index / 1000^to_index]
				double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
		}
		else if (options.i_useBit) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1000^from_index / (8 * 1024^to_index)]
				double deci_bin = std::pow(1000, static_cast<double>(origin)) / (8 * std::pow(1024, static_cast<double>(destination)));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [1000^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1000, power);
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using input_num * [1000^from_index / 1024^to_index]
				double deci_bin = std::pow(1000, static_cast<double>(origin)) / (std::pow(1024, static_cast<double>(destination)));
				result = std::stod(num) * deci_bin;
			}
			else
			{
				// result can be calculated using input_num * [1000^(from_index - to_index) / 8]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * (std::pow(1000, power) / 8);
			}
		}
		else if (options.i_useBoth) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num / 8 * [1024^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) / 8 * std::pow(1024, power);
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [1024^from_index / 1000^to_index]
				double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using input_num * [1024^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1024, power);
			}
			else
			{
				// result can be calculated using input_num / 8 * [1024^from_index / 1000^to_index]
				double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) / 8 * deci_bin;
			}
		}
		else /* default SI system */
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1000^from_index / 1024^to_index]
				double deci_bin = std::pow(1000, static_cast<double>(origin)) / std::pow(1024, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [8 * 1000^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * (8 * std::pow(1000, power));
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using 8 * input_num * [1000^from_index / 1024^to_index]
				double deci_bin = std::pow(1000, static_cast<double>(origin)) / std::pow(1024, static_cast<double>(destination));
				result = 8 * std::stod(num) * deci_bin;
			}
			else
			{
				// result can be calculated using input_num * [1000^(from_index - to_index)]
				double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1000, power);
			}
		}

		// calculate precision
		for (int i = 0; i < std::to_string(result).size(); i++)
		{
			if (std::to_string(result)[i] == '.')
			{
				std::string substr = std::to_string(result).substr(i, std::to_string(result).size());
				substr.erase(substr.find_last_not_of('0') + 1, std::string::npos);
				precision = substr.size() - 1;
			}
		}

		// toggle between scientific and fixed notation automatically
		if (result > 1e6 || result < 1e-6)
			str_stream << std::scientific << result;
		else
			str_stream << std::fixed << std::setprecision(precision) << result;

		return str_stream.str();
	}
	else
		return "Input can only contain numbers!";
}