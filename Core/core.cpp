// core.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "core.h"

std::string Core::Radix_Converter(std::string num, int origin, int base)
{
    std::fstream tempfile;
    tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

    std::string cmd = "python3 -O python/radix.py " + num + " " + std::to_string(origin) + " " + std::to_string(base);
    std::string result;

    system(cmd.c_str());
    std::getline(tempfile, result);
    
    tempfile.close();
    return result;
}