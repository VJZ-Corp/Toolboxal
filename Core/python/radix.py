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
    
    letterbasenumdict = { 10 : "a", 11 : "b", 12 : "c", 13 : "d", 14 : "e", 
                          15 : "f", 16 : "g", 17 : "h", 18 : "i", 19 : "j", 
                          20 : "k", 21 : "l", 22 : "m", 23 : "n", 24 : "o", 
                          25 : "p", 26 : "q", 27 : "r", 28 : "s", 29 : "t", 
                          30 : "u", 31 : "v", 32 : "w", 33 : "x", 34 : "y", 
                          35 : "z" }

    # Prevent invalid characters from being entered
    try:
        if origin == radix: # If the radices match, no need to perform any logic
            return number
        elif radix == 1:
            baseI = ""
            for i in range(base(number, origin, 10)):
                baseI += '1'
        elif origin > 10:

            baseI = 0
            number = str(number)[::-1]

            for i in range(len(number) - 1, -1, -1):
                try:
                    baseI += origin ** i * int(number[i]) # Increments origin^i * ith value of number
                except:
                    if get_key(number[i]) > origin + 1:
                        raise Exception
                    baseI += origin ** i * int(get_key(number[i])) # Increments origin^i * ith value of letterbasenumdict
        
            baseI = str(baseI)
            baseI = base(baseI, 10, radix) 

        elif origin == 10:

            j = int(number)
            baseI = ""
           
            while j != 0:
                if j % radix < 10:  # If (j / radix)'s remainder < 10, append (j / radix)'s remainder to base i
                    baseI += str(j % radix) 
                else: # append the value for (j / radix)'s remainder
                    baseI += letterbasenumdict[j % radix]

                j //= radix 
            
            # baseI reverses itself
            baseI = baseI[::-1]

        else:
            baseI = 0
            number = str(number)
        
            for i in range(len(number) - 1, -1, -1):
                baseI += origin ** i * int(number[i])
        
            baseI = str(baseI)
            baseI = base(baseI, 10, radix)
        
        return ' '.join([baseI[i:i+72] for i in range(0, len(baseI), 72)]) # insert space every 72 characters for textbox formatting

    except:
        return "Invalid symbols present in specified number."

if __name__ == "__main__":

    dirname = os.path.dirname(__file__)
    filename = os.path.join(dirname, '../databus.tmp')

    with open(filename, 'w') as temp:
        temp.write(base(sys.argv[1], int(sys.argv[2]), int(sys.argv[3])))