# radix.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import sys
import os

def base(number, origin, radix):

    # Gets key from letterbasenumdict
    def get_key(val): 
        for key, value in letterbasenumdict.items():
             if val == value:
                 return key
    
    isNegative = False
    letterbasenumdict = { 10 : "A", 11 : "B", 12 : "C", 13 : "D", 14 : "E", 
                          15 : "F", 16 : "G", 17 : "H", 18 : "I", 19 : "J", 
                          20 : "K", 21 : "L", 22 : "M", 23 : "N", 24 : "O", 
                          25 : "P", 26 : "Q", 27 : "R", 28 : "S", 29 : "T", 
                          30 : "U", 31 : "V", 32 : "W", 33 : "X", 34 : "Y", 
                          35 : "Z" }
    
    # Prevent invalid characters from being entered
    try:
        if str(number)[0] == "-":
            isNegative = True
            number = str(number)[1:len(str(number))]
        if origin > 10:
            number = number.upper()
            baseI = 0
            number = str(number)[::-1]

            for i in range(len(number) - 1, -1, -1):
                try:
                    baseI += origin ** i * int(number[i]) # Increments origin^i * ith value of number
                except:
                    if get_key(number[i]) > origin + 1:
                        raise Exception
                    baseI += origin ** i * int(get_key(number[i])) # Increments origin^i * ith value of letterbasenumdict
        
            baseI = base(baseI, 10, radix) 

        elif origin == 10:
            j = int(number)
            baseI = ""
           
            while j != 0:
                if j % radix < 10:  # If (j / radix)'s remainder < 10, append (j / radix)'s remainder to base i
                    baseI += str(j % radix) 
                else: # Append the value for (j / radix)'s remainder
                    baseI += letterbasenumdict[j % radix]

                j //= radix 
            
            # baseI reverses itself
            baseI = baseI[::-1]

        else:
            baseI = 0
            number = str(number)[::-1]
        
            for i in range(len(number) - 1, -1, -1):
                if int(number[i]) >= origin:
                    raise Exception
                baseI += origin ** i * int(number[i])
        
            baseI = base(baseI, 10, radix)

        if baseI == "":
            return '0'
        if isNegative:
            return "-" + baseI
        return baseI 

    except:
        return "Invalid string literal detected for specified radix."

if __name__ == "__main__":
    # Get relative paths for current file
    directory = os.path.dirname(__file__)
    file = os.path.join(directory, '../databus.tmp')

    with open(file, 'w') as temp:
        temp.write(base(sys.argv[1], int(sys.argv[2]), int(sys.argv[3])))