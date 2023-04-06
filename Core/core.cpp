// core.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "core.h"

bool isNumber(const std::string& str)
{
	char* end = nullptr;
	const double value = strtod(str.c_str(), &end);
	return end != str.c_str() && *end == '\0' && value != HUGE_VAL;
}

std::string Core::Radix_Converter(const std::string& num, int origin, int base)
{
	// filter out all whitespaces in given string
	if (!(num.find(' ') != std::string::npos))
	{
		std::fstream tempfile;
		tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

		const std::string cmd = "vendor\\python3.9_x64amd\\pythonw.exe scripts/radix.py " + num + " " + std::to_string(origin) + " " + std::to_string(base);
		std::string result;

		PROCESS_INFORMATION p_info;
		STARTUPINFO s_info;
		DWORD ReturnValue;
		const CA2W lpwstr(cmd.c_str());

		memset(&s_info, 0, sizeof s_info);
		memset(&p_info, 0, sizeof p_info);
		s_info.cb = sizeof s_info;

		if (CreateProcess(nullptr, lpwstr, nullptr, nullptr, 0, 0, nullptr, nullptr, &s_info, &p_info))
		{
			WaitForSingleObject(p_info.hProcess, 9999);
			GetExitCodeProcess(p_info.hProcess, &ReturnValue);
			CloseHandle(p_info.hProcess);
			CloseHandle(p_info.hThread);
		}

		std::getline(tempfile, result);
		tempfile.close();
		return result;
	}

	return "Invalid string literal detected for specified radix.";
}

std::string Core::Logic_Gates(const std::string& num1, const std::string& num2, int gate)
{
	std::fstream tempfile;
	tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

	std::string cmd = "vendor\\python3.9_x64amd\\pythonw.exe scripts/bitwise.py " + num1 + " " + num2;
	std::string result;

	switch (gate)
	{
		case 0:  cmd += " AND";	  break;
		case 1:	 cmd += " OR";	  break;
		case 2:	 cmd += "1 NOT";  break;
		case 3:	 cmd += " NOR";   break;
		case 4:	 cmd += " XOR";   break;
		case 5:  cmd += " NAND";  break;
		case 6:  cmd += " XNOR";  break;
	}

	PROCESS_INFORMATION p_info;
	STARTUPINFO s_info;
	DWORD ReturnValue;
	const CA2W lpwstr(cmd.c_str());

	memset(&s_info, 0, sizeof s_info);
	memset(&p_info, 0, sizeof p_info);
	s_info.cb = sizeof s_info;

	if (CreateProcess(nullptr, lpwstr, nullptr, nullptr, 0, 0, nullptr, nullptr, &s_info, &p_info))
	{
		WaitForSingleObject(p_info.hProcess, 9999);
		GetExitCodeProcess(p_info.hProcess, &ReturnValue);
		CloseHandle(p_info.hProcess);
		CloseHandle(p_info.hThread);
	}

	std::getline(tempfile, result);
	tempfile.close();

	if (!result.empty())
		return result;

	return "Toolboxal is currently experiencing some issues. Please try again later.";
}

std::string Core::Bitshifter(const std::string& num1, const std::string& num2, int operation)
{
	std::fstream tempfile;
	tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

	std::string cmd = "vendor\\python3.9_x64amd\\pythonw.exe scripts/bitwise.py " + num1 + " " + num2;
	std::string result;

	switch (operation)
	{
		case 7:   cmd += " LEFT";	 break;
		case 8:	  cmd += " RIGHT";	 break;
		case 9:	  cmd += " ROT_L";	 break;
		case 10:  cmd += " ROT_R";   break;
	}

	PROCESS_INFORMATION p_info;
	STARTUPINFO s_info;
	DWORD ReturnValue;
	const CA2W lpwstr(cmd.c_str());

	memset(&s_info, 0, sizeof s_info);
	memset(&p_info, 0, sizeof p_info);
	s_info.cb = sizeof s_info;

	if (CreateProcess(nullptr, lpwstr, nullptr, nullptr, 0, 0, nullptr, nullptr, &s_info, &p_info))
	{
		WaitForSingleObject(p_info.hProcess, 9999);
		GetExitCodeProcess(p_info.hProcess, &ReturnValue);
		CloseHandle(p_info.hProcess);
		CloseHandle(p_info.hThread);
	}

	std::getline(tempfile, result);
	tempfile.close();

	if (!result.empty())
		return result;
	
	return "Toolboxal is currently experiencing some issues. Please try again later.";
}

std::string Core::Magnitude_Converter(const std::string& num, int origin, int destination, RadioButtonOptions options)
{
	// filter out any string literals that are not numbers
	if (isNumber(num))
	{
		// format result based on locale
		double result, precision = 0;
		std::stringstream str_stream;
		str_stream.imbue(std::locale(""));

		if (options.i_useBin) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1024^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1024, power);
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [8 * 1024^from_index / 1000^to_index]
				const double deci_bin = 8 * std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using 8 * input_num * [1024^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = 8 * std::stod(num) * std::pow(1024, power);
			}
			else
			{
				// result can be calculated using input_num * [1024^from_index / 1000^to_index]
				const double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
		}
		else if (options.i_useBit) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1000^from_index / (8 * 1024^to_index)]
				const double deci_bin = std::pow(1000, static_cast<double>(origin)) / (8 * std::pow(1024, static_cast<double>(destination)));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [1000^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1000, power);
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using input_num * [1000^from_index / 1024^to_index]
				const double deci_bin = std::pow(1000, static_cast<double>(origin)) / (std::pow(1024, static_cast<double>(destination)));
				result = std::stod(num) * deci_bin;
			}
			else
			{
				// result can be calculated using input_num * [1000^(from_index - to_index) / 8]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * (std::pow(1000, power) / 8);
			}
		}
		else if (options.i_useBoth) 
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num / 8 * [1024^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) / 8 * std::pow(1024, power);
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [1024^from_index / 1000^to_index]
				const double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using input_num * [1024^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1024, power);
			}
			else
			{
				// result can be calculated using input_num / 8 * [1024^from_index / 1000^to_index]
				const double deci_bin = std::pow(1024, static_cast<double>(origin)) / std::pow(1000, static_cast<double>(destination));
				result = std::stod(num) / 8 * deci_bin;
			}
		}
		else /* default SI system */
		{
			if (options.o_useBin)
			{
				// result can be calculated using input_num * [1000^from_index / 1024^to_index]
				const double deci_bin = std::pow(1000, static_cast<double>(origin)) / std::pow(1024, static_cast<double>(destination));
				result = std::stod(num) * deci_bin;
			}
			else if (options.o_useBit)
			{
				// result can be calculated using input_num * [8 * 1000^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * (8 * std::pow(1000, power));
			}
			else if (options.o_useBoth)
			{
				// result can be calculated using 8 * input_num * [1000^from_index / 1024^to_index]
				const double deci_bin = std::pow(1000, static_cast<double>(origin)) / std::pow(1024, static_cast<double>(destination));
				result = 8 * std::stod(num) * deci_bin;
			}
			else
			{
				// result can be calculated using input_num * [1000^(from_index - to_index)]
				const double power = static_cast<double>(origin) - static_cast<double>(destination);
				result = std::stod(num) * std::pow(1000, power);
			}
		}

		// calculate precision
		for (size_t i = 0; i < std::to_string(result).size(); i++)
		{
			if (std::to_string(result)[i] == '.')
			{
				std::string substr = std::to_string(result).substr(i, std::to_string(result).size());
				substr.erase(substr.find_last_not_of('0') + 1, std::string::npos);
				precision = substr.size() - 1;
			}
		}

		// toggle between scientific and fixed notation automatically
		if (std::abs(result) > 1e6 || std::abs(result) < 1e-6)
			str_stream << std::scientific << result;
		else
			str_stream << std::fixed << std::setprecision(precision) << result;

		return str_stream.str();
	}
	
	return "Input can only contain numbers!";
}

std::string Core::Search(const std::string& query, const std::string& querySize)
{
	std::fstream tempfile;
	tempfile.open("databus.tmp", std::fstream::in | std::fstream::out | std::fstream::trunc);

	const std::string cmd = "vendor\\python3.9_x64amd\\pythonw.exe scripts/crawler.py " + querySize + " \"" + query + "\"";
	std::string line, result;

	PROCESS_INFORMATION p_info;
	STARTUPINFO s_info;
	DWORD ReturnValue;
	const CA2W lpwstr(cmd.c_str());

	memset(&s_info, 0, sizeof(s_info));
	memset(&p_info, 0, sizeof(p_info));
	s_info.cb = sizeof(s_info);

	if (CreateProcess(nullptr, lpwstr, nullptr, nullptr, 0, 0, nullptr, nullptr, &s_info, &p_info))
	{
		WaitForSingleObject(p_info.hProcess, 9999);
		GetExitCodeProcess(p_info.hProcess, &ReturnValue);
		CloseHandle(p_info.hProcess);
		CloseHandle(p_info.hThread);
	}

	while (std::getline(tempfile, line))
	{
		if (line.empty()) break;
		const std::string hyperlink = "<a href=\"" + line + "\">" + line + "</a><br><br>";
		result += hyperlink;
	}

	tempfile.close();
	return result;
}