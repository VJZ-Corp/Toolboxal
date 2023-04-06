# crawler.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import os
import sys 
import googlesearch

# Get relative paths for current file
directory = os.path.dirname(__file__)
temp = os.path.join(directory, '../databus.tmp')
size = int(sys.argv[1])
query = sys.argv[2]

with open(temp, "w") as file:
    try:
        for i in googlesearch.search(query, tld="com", num=size, stop=size, pause=3): 
            file.write(i + '\n')
    except Exception as e:
        file.write(str(e))