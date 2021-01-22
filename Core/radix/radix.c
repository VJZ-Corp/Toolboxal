// radix.c

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "radix.h"

const char* Core::Radix::Converter(const char* num, int origin, int radix)
{
	// spawns a 128-byte buffer
	char buffer[128];

	// executes radix.py 
	char* cmd = "python3 -O ./radix.py";
	system(cmd);

	// create a file pointer for parsing output of radix.py
	FILE* fileptr = _popen(cmd, "r");
	const char* output = "";

	while (fgets(buf, BUFSIZE, fp) != NULL)
		output += buf;

	return output;
}