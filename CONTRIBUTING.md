# Contributing Guidelines
Before getting started, please read this document as it contains all the necessary information in regards to how to effectively contribute to Toolboxal. Any contributing expectations will be explicitly outlined in this markdown file.

<h2>Cloning & Project Setup</h2>
To clone Toolboxal, run 

```
$ git clone https://github.comVJZ-Corp/Toolboxal
```

in your current working directory. Alternatlvely, you can download a raw zip file and extracting it to your working directory. Almost all of Toolboxal is built using Visual Studio 2019. Therefore it is recommended that you have Visual Studio 10.0.40219.1 or later versions. Import the solution file (Toolboxal.sln) in the root directory by double-clicking it in file explorer or following the instructions provided by Visual Studio. Make sure to install [Qt VS Tools for Visual Studio 2019](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2019) or else many compiler and linkage errors will appear. *This assumes you have the latest version of Qt installed: Qt 6.0.0.*

<h2>Licensing</h2>
Any code written must conform to our licensing convention, which shall be placed on the first line of every source code file except for auto-generated files. Below are some examples for different common languages.

C/C++:
```
// filename.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#include <stdlib.h>
#include <iostream>
```

Java/C#:
```
// filename.java

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

import java.util.*;
import java.io.*;
```

Python:
```
# filename.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import sys
import math
```

