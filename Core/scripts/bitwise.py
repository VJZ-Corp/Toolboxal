# bitwise.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import os
import sys

g_Radix = 0 
g_errorMsg = "Invalid string literal detected for specified radix."

def base(number, origin, radix):

    # Gets key from letterbasenumdict
    def get_key(val): 
        for key, value in letterbasenumdict.items():
             if val == value:
                 return key
    
    letterbasenumdict = { 10 : "A", 11 : "B", 12 : "C", 13 : "D", 14 : "E", 
                          15 : "F", 16 : "G", 17 : "H", 18 : "I", 19 : "J", 
                          20 : "K", 21 : "L", 22 : "M", 23 : "N", 24 : "O", 
                          25 : "P", 26 : "Q", 27 : "R", 28 : "S", 29 : "T", 
                          30 : "U", 31 : "V", 32 : "W", 33 : "X", 34 : "Y", 
                          35 : "Z" }

    # Prevent invalid characters from being entered
    try:
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
        
        return baseI 

    except:
        return "Invalid string literal detected for specified radix."

def AND(a, b):
    return a & b

def OR(a, b):
    return a | b

def NOT(a):
    return ~a

def NOR(a, b):
    return NOT(OR(a, b)) 

def NAND(a, b):
    return NOT(AND(a, b))

def XOR(a, b):
    return a ^ b

def XNOR(a, b):
    return NOT(XOR(a, b))

def checkBase(num):

    global g_Radix
    global g_errorMsg

    try:
        if num[0:2] == "0b":
            g_Radix = 2
            return int(base(num[2:len(num)], 2, 10))
        elif num[0:2] == "0x":
            g_Radix = 16
            return int(base(num[2:len(num)], 16, 10))
    except:
        return g_errorMsg

    try:
        g_Radix = 10
        return int(num)
    except:
        return g_errorMsg

if __name__ == "__main__":

    dir = os.path.dirname(__file__)
    file = os.path.join(dir, '../databus.tmp')
    
    argv1 = checkBase(sys.argv[1])
    argv2 = checkBase(sys.argv[2])

    if argv1 == g_errorMsg or argv2 == g_errorMsg:
        temp = open(file, 'w')
        temp.write(g_errorMsg)
        temp.close()
        sys.exit()

    if sys.argv[3] == "AND":
        result = AND(argv1, argv2)
    elif sys.argv[3] == "OR":
        result = OR(argv1, argv2)
    elif sys.argv[3] == "NOT":
        result = NOT(argv1)
    elif sys.argv[3] == "NOR":
        result = NOR(argv1, argv2)
    elif sys.argv[3] == "NAND":
        result = NAND(argv1, argv2)
    elif sys.argv[3] == "XNOR":
        result = XNOR(argv1, argv2)
    elif sys.argv[3] == "XOR":
        result = XOR(argv1, argv2)

    result = base(result, 10, g_Radix)

    if g_Radix == 2:
        result = "0b" + str(result)
    elif g_Radix == 16:
        result = "0x" + str(result)

    with open(file, 'w') as temp:
        temp.write(result)