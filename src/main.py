from src.args import Args, Algorithm, Mode
from src.xor import xor
from src.aes.logic import encrypt as aesEncrypt
from src.aes.logic import encrypt as aesDecrypt
from src.rsa.logic import encrypt as rsaEncrypt
from src.rsa.logic import decrypt as rsaDecrypt
from src.aes.key import Key, genereateAllKeys

def main():
    args = Args()

    try:
        args.parse()
    except ValueError as e:
        print(f"Error: {e}")
        return 84

    if (args.help):
        args.printHelp()
        return 0

    message = ""
    if (args.mode != Mode.GEN_RSA_KEY):
        message = bytes.fromhex(input())

    functionTableEncrypt = [xor, rsaEncrypt, aesEncrypt]
    functionTableDecrypt = [xor, rsaDecrypt, aesDecrypt]
    if (args.mode == Mode.ENCRYPT or args.mode == Mode.GEN_RSA_KEY):
        message = functionTableEncrypt[args.algo.value](message, args)
    else:
        message = functionTableDecrypt[args.algo.value](message, args)
