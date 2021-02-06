# bitwise.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import os
import sys

g_Radix = 0 
g_errorMsg = "Invalid string literal detected for specified radix."

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

def rightShift(a, b):
    return a >> b

def leftShift(a, b):
    return a << b

def rotateRight(a, b):
    return (a >> b) | (a << (32 - b)) & 0xFFFFFFFF

def rotateLeft(a, b):
    return (a << b) | (a >> (32 - b))
   
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

    sys.path.append(dir)
    from radix import base
    
    argv1 = checkBase(sys.argv[1])
    arg1Radix = g_Radix
    argv2 = checkBase(sys.argv[2])
    arg2Radix = g_Radix

    if argv1 == g_errorMsg or argv2 == g_errorMsg:
        temp = open(file, 'w')
        temp.write(g_errorMsg)
        temp.close()
        sys.exit()

    if sys.argv[3] == "RIGHT":
        result = rightShift(argv1, argv2)
        if arg1Radix == 2:
            result = base(result, 10, 2)
            result = "0b" + str(result)
        elif arg1Radix == 16:
            result = base(result, 10, 16)
            result = "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "LEFT":
        result = leftShift(argv1, argv2)
        if arg1Radix == 2:
            result = base(result, 10, 2)
            result = "0b" + str(result)
        elif arg1Radix == 16:
            result = base(result, 10, 16)
            result = "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "ROT_L":
        result = rotateLeft(argv1, argv2)
        if arg1Radix == 2:
            result = base(result, 10, 2)
            result = "0b" + str(result)
        elif arg1Radix == 16:
            result = base(result, 10, 16)
            result = "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "ROT_R":
        result = rotateRight(argv1, argv2)
        if arg1Radix == 2:
            result = base(result, 10, 2)
            result = "0b" + str(result)
        elif arg1Radix == 16:
            result = base(result, 10, 16)
            result = "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "AND":
        result = AND(argv1, argv2)
    elif sys.argv[3] == "OR":
        result = OR(argv1, argv2)
    elif sys.argv[3] == "NOT":
        result = NOT(argv1)
        if arg1Radix == 2:
            if result < 0:
                result = base(result, 10, 2)
                result = "-0b" + result.replace("-", "")
            else:
                result = base(result, 10, 2)
                result = "0b" + str(result)
        elif arg1Radix == 16:
            if result < 0:
                result = base(result, 10, 16)
                result = "-0x" + result.replace("-", "")
            else:
                result = base(result, 10, 16)
                result = "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "NOR":
        result = NOR(argv1, argv2)
    elif sys.argv[3] == "NAND":
        result = NAND(argv1, argv2)
    elif sys.argv[3] == "XNOR":
        result = XNOR(argv1, argv2)
    elif sys.argv[3] == "XOR":
        result = XOR(argv1, argv2)

    result = base(result, 10, arg1Radix)

    if arg1Radix == 2 and arg2Radix == 2:
        result = "0b" + str(result)
    elif arg1Radix == 16 and arg2Radix == 16:
        result = "0x" + str(result)
    elif arg1Radix == 10 and arg2Radix == 10:
        result = str(result)
    else:
        result = "Input radices must match!"

    with open(file, 'w') as temp:
        temp.write(result)