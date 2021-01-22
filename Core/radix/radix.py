# radix.py

# Copyright (C) 2021 by VJZ Corporation.
# SPDX-License-Identifier: GPL-3.0-only

import sys

def radix(number, origin, radix):

    letterbasenumdict = {10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f", 16:"g", 17:"h", 18:"i", 19:"j", 20:"k", 21:"l", 22:"m", 23:"n", 24:"o", 25:"p", 26:"q", 27:"r", 28:"s", 29:"t", 30:"u", 31:"v", 32:"w", 33:"x", 34:"y", 35:"z"}
    
    if origin == radix: 
        return number
    elif origin > 10:
        pass #later
    elif origin == 10:

        j = number
        baseI = ""
        
        while j != 0:
            if j % base < 10:
                baseI += str(int(j % radix)) 
            else:
                baseI += letterBaseNumDict[j % radix]
            
            j //= radix 
            baseI = baseI[::-1]

    else:
        baseI = 0
        number = str(number)
        
        for i in range(len(number)-1, -1, -1):
            baseI += origin ** i * int(number[i])
        
        baseI = str(baseI)
        radix(baseI, 10, radix)
        
    return baseI

if __name__ == "__main__":
    print(radix(sys.argv[0], sys.argv[1], sys.argv[2]))