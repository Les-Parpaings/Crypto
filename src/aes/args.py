
from src.args import Args

def blockMessage(message: str, args: Args) -> list[bytes]:
    list = []

    if (len(message) != len(args.key)):
        raise("message size different from key size")

    list.append(bytes.fromhex(message))
    return list

def cutMessage(message: str):
    list = []
    index = 0

    while (True):
        string = ""
        for i in range(32):
            if (i + index < len(message)):
                string = string + message[i + index]
            else:
                string = string + '0'
        list.append(bytes.fromhex(string))

        index += 32
        if (index >= len(message)):
            break

    return list


def parseMessage(message: str, args: Args) -> list[bytes]:
    if (args.block):
        return blockMessage(message, args)
    else:
        return cutMessage(message)
