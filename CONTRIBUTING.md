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

<h2>External Python Libraries</h2>
The use of external Python libraries is allowed. However, you must follow convention when it comes to integrating Python libraries into Toolboxal. First and foremost, to ensure that the interpreter can resolve Python modules, you must place the actual package of the Python library in <em>vendor/python3.9_x64amd</em>. You can do this easily by:

```
$ cd vendor/python3.9_x64amd
$ pip3 install package-name -t .
```
The library will generate package-info folder, which must be placed in the vendor directory. On Windows 10, open cmd.exe and type:

```
$ cd vendor/python3.9_x64amd
$ xcopy /e packagename-info ../packagename-info
$ rmdir /s /q packagename-info
```

<h2>Pull Request Formats</h2>
To submit a pull request, you must include the following OR ELSE YOUR PR WILL BE IGNORED:

1. You must add the appropriate labels to your pull request.
2. The title must briefly describe your changes.
3. The body of the PR should contain:
    - Which files you changed.
    - The reason for changing the files.
    - What issue or feature will you add to Toolboxal.
4. It must not contain any of the following:
    - Issues or features that have already been fixed or added in.
    - Any form of advertisements.
    - Any off-topic discussions.
