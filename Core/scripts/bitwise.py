# bitwise.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import os
import sys

g_Radix = 0 
g_errorMsg = "Invalid string literal detected for specified radix."

AND = lambda a, b: a & b
OR = lambda a, b: a | b
NOT = lambda a: ~a
XOR = lambda a, b: a ^ b
NOR = lambda a, b: NOT(OR(a, b))
NAND = lambda a, b: NOT(AND(a, b))
XNOR = lambda a, b: NOT(XOR(a, b)) 
rightShift = lambda a, b: a >> b
leftShift = lambda a, b: a << b
rotateRight = lambda a, b: (a >> b % 64 | a << 64 - b % 64) & 0xFFFFFFFFFFFFFFFF
rotateLeft = lambda a, b: (a << b % 64 | a >> 64 - b % 64) & 0xFFFFFFFFFFFFFFFF

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

    directory = os.path.dirname(__file__)
    file = os.path.join(directory, '../databus.tmp')

    sys.path.append(directory)
    from radix import base

    argv1 = checkBase(sys.argv[1])
    arg1Radix = g_Radix
    argv2 = checkBase(sys.argv[2])
    arg2Radix = g_Radix
    singleArgs = False

    if argv1 == g_errorMsg or argv2 == g_errorMsg:
        with open(file, 'w') as temp:
            temp.write(g_errorMsg)
            temp.close()
            sys.exit()

    if sys.argv[3] == "RIGHT":
        result = rightShift(argv1, argv2)
        singleArgs = True
    elif sys.argv[3] == "LEFT":
        result = leftShift(argv1, argv2)
        singleArgs = True
    elif sys.argv[3] == "ROT_L":
        result = rotateLeft(argv1, argv2)
        singleArgs = True
    elif sys.argv[3] == "ROT_R":
        result = rotateRight(argv1, argv2)
        singleArgs = True
    elif sys.argv[3] == "NOT":
        result = NOT(argv1)
        singleArgs = True

    if singleArgs:
        if arg1Radix == 2:
            result = base(result, 10, 2)
            result = "-0b" + str(result).replace("-", "") if int(result) < 0 else "0b" + str(result)
        elif arg1Radix == 16:
            result = base(result, 10, 16)
            result = "-0x" + str(result).replace("-", "") if int(result, 16) < 0 else "0x" + str(result)
        else:
            result = str(result)

        with open(file, 'w') as temp:
            temp.write(result)
            sys.exit()

    elif sys.argv[3] == "AND":
        result = AND(argv1, argv2)
    elif sys.argv[3] == "OR":
        result = OR(argv1, argv2)
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
        result = "0b" + str(result) if int(result) > 0 else "-0b" + str(result).replace("-", "")
    elif arg1Radix == 16 and arg2Radix == 16:
        result = "0x" + str(result) if int(result) > 0 else "-0x" + str(result).replace("-", "")
    elif arg1Radix == 10 and arg2Radix == 10:
        result = str(result)
    else:
        result = "Input radices must match!"

    with open(file, 'w') as temp:
        temp.write(result)