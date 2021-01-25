// core.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#pragma once

#ifndef CORE_H
#define CORE_H

#include <fstream>
#include <string>

namespace Core
{
	std::string Radix_Converter(std::string num, int origin, int base);
}


#endif //CORE_H
