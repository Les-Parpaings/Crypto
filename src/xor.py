
from src.args import Args

def xor(message: str, args: Args):
    message = bytes.fromhex(message)
    key = bytes.fromhex(args.key)

    sizeMessage = len(message)
    sizeKey = len(key)

    try:
        if (args.block):
            if (sizeMessage != sizeKey):
                raise("message size different from key size")
    except ValueError as e:
        print(f"Error: {e}")
        exit(84)

    result = []
    for i in range(sizeMessage):
        result.append(message[i] ^ key[i % sizeKey])

    return bytes(result).hex()
