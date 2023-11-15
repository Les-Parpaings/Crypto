# args.py

import sys
from enum import Enum

class Mode(Enum):
    NONE = -1,
    ENCRYPT = 0,
    DECRYPT = 1,
    GEN_RSA_KEY = 2,

class Algorithm(Enum):
    NONE = -1
    XOR = 0
    RSA = 1
    AES = 2
    PGP = 3
    SIZE = 4

PATH_HELP = "assets/help.txt"

class Args:
    def __init__(self):
        self.mode = Mode.NONE
        self.algo = Algorithm.NONE
        self.help = False
        self.block = False
        self.P = 0
        self.Q = 0
        self.key = ""

    def parse(self):

        list = sys.argv
        del list[0]
        if (not list):
            raise("no arguments provided")

        for arg in list[:]:
            if (arg == "-h" or arg == "--help"):
                self.help = True
                return
            if (arg == "-xor"):
                self.algo = Algorithm.XOR
                list.remove(arg)
            if (arg == "-rsa"):
                self.algo = Algorithm.RSA
                list.remove(arg)
            if (arg == "-aes"):
                self.algo = Algorithm.AES
                list.remove(arg)
            if (arg == "-pgp"):
                self.algo = Algorithm.PGP
                list.remove(arg)
            if (arg == "-c"):
                self.mode = Mode.ENCRYPT
                list.remove(arg)
            if (arg == "-d"):
                self.mode = Mode.DECRYPT
                list.remove(arg)
            if (arg == "-b"):
                self.block = True
                list.remove(arg)
            if (arg == "-g"):
                self.mode = Mode.GEN_RSA_KEY
                list.remove(arg)

        if (self.mode == Mode.NONE):
            raise ValueError("can't find encrypt or decrypt mode")
        if (self.algo == Algorithm.NONE):
            raise ValueError("can't find algorithm to use")
        if (self.block and (self.algo != Algorithm.XOR and self.algo != Algorithm.AES)):
            raise ValueError("can't find algorithm to use")
        if (self.mode == Mode.GEN_RSA_KEY and self.algo != Algorithm.RSA):
            raise ValueError("-g option must be with rsa algorithm")
        if (self.mode == Mode.GEN_RSA_KEY):
            if (len(list) < 2):
                raise ValueError("not enough arguments")
            self.P = int.from_bytes(bytes.fromhex(list[0]), "little")
            self.Q = int.from_bytes(bytes.fromhex(list[1]), "little")
            return
        self.key = list[0]

    def printHelp(self):
        print(open(PATH_HELP, 'r').read())
