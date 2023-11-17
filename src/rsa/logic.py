def encrypt(message, args):
    publicKey = args.key
    e = int.from_bytes(bytes.fromhex(publicKey.split("-")[0]), 'little')
    n = int.from_bytes(bytes.fromhex(publicKey.split("-")[1]), 'little')
    intToCipher = int.from_bytes(message, 'little')
    cipher = pow(intToCipher, e, n)
    return cipher.to_bytes((cipher.bit_length() + 7) // 8, 'little').hex()

def decrypt(message, args):
    private_key = args.key
    d = int.from_bytes(bytes.fromhex(private_key.split("-")[0]), 'little')
    n = int.from_bytes(bytes.fromhex(private_key.split("-")[1]), 'little')
    intToPlain = int.from_bytes(message, 'little')
    plain = pow(intToPlain, d, n)
    return plain.to_bytes((plain.bit_length() + 7) // 8, 'little').hex()
