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

struct RadioButtonOptions
{
	bool i_useBit; bool i_useBin; bool i_useBoth;
	bool o_useBit; bool o_useBin; bool o_useBoth;
};

namespace Core
{
	std::string Radix_Converter(std::string num, int origin, int base);
	std::string Logic_Gates(std::string num1, std::string num2, int gate);
	std::string Bitshifter(std::string num1, std::string num2, int operation);
	std::string Magnitude_Converter(std::string num, int origin, int destination, RadioButtonOptions options);
}

#endif //CORE_H
