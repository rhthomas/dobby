#!/usr/bin/env python3
# George's script to fill the progmem 1array in memory.h

""" Empty memory generator for drenchwood machine

Quick hack script, move along.
"""

def main():
    MEM_START = 0x0000
    MEM_END = 0x00FF

    INDENT = "\t"
    FILL = 0x00
    DATA_FORMAT = "04X"
    ADDRESS_FORMAT = "04X"

    WORDS_PER_ROW = 8

    for idx in range(MEM_START, MEM_END, WORDS_PER_ROW):
        print(INDENT, end="")
        print(
            ("0x" + format(FILL, DATA_FORMAT) +", ")*WORDS_PER_ROW,
            end=""
        )
        if idx == (MEM_END-(WORDS_PER_ROW-1)):
            print("\b\b  ", end="")
        print(
            "// 0x"
            + format(idx, ADDRESS_FORMAT)
            + " - "
            + "0x" + format(idx + WORDS_PER_ROW - 1, ADDRESS_FORMAT)
        )
        #FILL = (FILL+1)%256

if __name__=="__main__":
    main()
