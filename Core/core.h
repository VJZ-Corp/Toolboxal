// core.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#pragma once

#ifndef CORE_H
#define CORE_H

#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cctype>    
#include <iomanip>
#include <locale>
#include <sstream>
#include <atlbase.h>
#include <atlconv.h>
#include <windows.h>

struct RadioButtonOptions
{
	bool i_useBit; bool i_useBin; bool i_useBoth;
	bool o_useBit; bool o_useBin; bool o_useBoth;
};

namespace Core
{
	std::string Radix_Converter(const std::string& num, int origin, int base);
	std::string Logic_Gates(const std::string& num1, const std::string& num2, int gate);
	std::string Bitshifter(const std::string& num1, const std::string& num2, int operation);
	std::string Magnitude_Converter(const std::string& num, int origin, int destination, RadioButtonOptions options);
	std::string Search(const std::string& query, const std::string& querySize);
}

#endif //CORE_H
