def xor(message, args):
    key = bytes.fromhex(args.key)
    result = []
    size = len(message)
    if (args.block):
        size = len(key)
    for i in range(size):
        result.append(message[i] ^ key[i % len(key)])
    return bytes(result).hex()
