# Toolboxal [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

<img src="./logo.png" width="999">

Toolboxal is a user-friendly application with its audience targeted mainly towards programmers and software engineers. It contains many useful tools and guides designed to speed up workflow, all of which are packaged into one portable application for anyone to run.

<h2> Downloading & Installing Toolboxal </h2>

Toolboxal's installer can be found in the "releases" tab on the right-hand side of the project's github page. Alternatively, you can go to https://github.com/VJZ-Corp/Toolboxal/releases to find the release binaries for Toolboxal. 

The release packages are named as follows: <b>toolboxal-vA.B_x64.exe</b>, with "A" being the major release version and "B" being minor release updates. Unfortunately, Toolboxal only runs on x64 machines as VJZ Corporation is in the process of deprecating legacy x86 API. 

Installing Toolboxal should be straightforward: run the .exe file and follow the instructions on the wizard. The installer will setup every file Toolboxal needs to run and create a shortcut on the desktop (if specified). 

<h2>Usage</h2>
<h4>Radix Converter</h4>
The radix converter is a tool that can convert between radices. Simply enter your original number and its radix, the radix you want to convert to, and you are all set. Toolboxal will calculate the result based on your inputs. Toolboxal only supports 35 radices from base 2 to base 36. You can enter a mixture of uppercase and lowercase letters, but Toolboxal treats both cases as the same.

<h4>Data Storage Units Converter</h4>
The data storage unit converter will convert between all supported prefixes of any data unit (SI, binary, bits, bytes). You can find all the available data storage units that Toolboxal supports here: https://en.wikipedia.org/wiki/Orders_of_magnitude_(data). Simply enter your current unit, the unit you are trying to convert to, and Toolboxal will automatically convert the data for you. Furthermore, you can check the radio buttons to use different systems of units.

<h4>Bitwise Calculator</h4>
The bitwise calculator supports calculations between all 7 common logic gates: AND, NAND, OR, NOR, XOR, XNOR, and NOT. It also supports bitwise left shift (<<), bitwise right shift (>>), and circular bit rotation (left & right). **NOTE: In Python, integer values are not limited to a fixed number of bits and can grow to an arbitrary size. Therefore, circular bit rotations wrap after 64 bits.** You can input numbers in base 2 (must be prefixed with "0b"), base 16 (must be prefixed with "0x"), and base 10 (no prefix). The bitwise calculator currently does not support operations for negative numbers (i.e. inputs cannot contain the negative sign).

<h4>Search Tool</h4>
The search tool is used to search for errors and bugs that you may encounter within your development experience. The search tool uses Google to index search results and will return the top results as URLs in which you can click on to open. Sometimes, Google may give you an error or an exception, that is outside of Toolboxal's control and you should not report that particular exception as an issue. 
<br>
<em>Few things to consider: You are not allowed to enter an URL as your search query. The search tool is slow on purpose as to prevent Google from blocking your IP address. </em>

<h2>Contributing</h2>
The details of contributing are highlighted in "CONTRIBUTING.md" in the project's root directory. Please follow the contributing guidelines strictly as any abusers will be banned from contributing permanently. "CONTRIBUTING.md" can also be found here at https://github.com/VJZ-Corp/Toolboxal/blob/master/CONTRIBUTING.md.
