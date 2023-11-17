def xor(message, args):
    key = bytes.fromhex(args.key)
    result = []
    size = len(message)
    if (args.block):
        size = len(args.key)
    for i in range(size):
        result.append(message[i] ^ args.key[i % len(args.key)])
    return bytes(result).hex()
