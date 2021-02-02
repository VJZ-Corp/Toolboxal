# Contributing Guidelines
Before getting started, please read this document as it contains all the necessary information apropros of how to effectively contribute to Toolboxal. Any contributing expectations will be explicitly outlined in this markdown file. <b> All contributors must adhere to our code of conduct, which can be found here: https://github.com/VJZ-Corp/Toolboxal/blob/master/CODE_OF_CONDUCT.md</b>

<h2>Cloning & Project Setup</h2>
To clone Toolboxal, run 

```
$ git clone https://github.com/VJZ-Corp/Toolboxal
```
in your current working directory. Alternatlvely, you can download a raw zip file and extract it to your working directory. 

Almost all of Toolboxal is built using Visual Studio 2019. Therefore it is recommended that you have Visual Studio 10.0.40219.1 or later versions. Import the solution file (Toolboxal.sln) in the root directory by double-clicking it in file explorer or following the instructions provided by Visual Studio. 

Make sure to install [Qt VS Tools for Visual Studio 2019](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2019) or else many compiler and/or linkage errors will appear. *This assumes you have the latest version of Qt installed: Qt 6.0.0.*

<h2>Licensing</h2>
Any code written must conform to our licensing convention, which shall be placed on the first line of every source code file except for auto-generated files. Below are some examples for different common languages.

C/C++:
```cpp
// filename.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#include <stdlib.h>
#include <iostream>
```

Java/C#:
```java
// filename.java

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

import java.util.*;
import java.io.*;
```

Python:
```python
# filename.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import sys
import math
```

