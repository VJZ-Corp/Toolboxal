// radix.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#pragma once

#ifndef RADIX_H
#define RADIX_H

#include <stdlib.h>
#include <stdio.h>

namespace Core::Radix
{
	const char* Converter(const char* num, int origin, int radix);
}

#endif //RADIX_H
