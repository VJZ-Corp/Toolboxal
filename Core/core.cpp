// core.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "core.h"

std::string Core::Radix_Converter(std::string num, int origin, int base)
{
	if (!(num.find(' ') != std::string::npos))
	{
		std::fstream tempfile;
		tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::string cmd = "python3 -O scripts/radix.py " + num + " " + std::to_string(origin) + " " + std::to_string(base);
		std::string result;

		system(cmd.c_str());
		std::getline(tempfile, result);

		tempfile.close();
		return result;
	}
	else
		return "Invalid string literal detected for specified radix.";
}

std::string Core::Magnitude_Converter(std::string num, int origin, int destination, RadioButtonOptions options)
{
	if (std::all_of(num.begin(), num.end(), ::isdigit))
	{
		if (options.i_useBin)
		{
			return num; // to-do: implement
		}
		else
		{
			double power = static_cast<double>(destination) - static_cast<double>(origin);
			double result = std::pow(std::stod(num), 0) * std::pow(1000, power);
			return std::to_string(result);
		}
	}
	else
		return "Input can only contain numbers!";
}

