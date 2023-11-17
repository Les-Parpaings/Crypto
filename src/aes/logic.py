
from src.args import Mode, Algorithm, Args
from src.aes.key import Key, Word, genereateAllKeys

def encrypt(message: str, args: Args) -> str:
    allKeys = genereateAllKeys(bytes.fromhex(args.key))
    for key in allKeys:
        print(key)
    return message

def decrypt(message, args) -> str:
    print("todo")
    return message
