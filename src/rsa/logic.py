from src.args import Mode
from src.rsa.generateKeys import genRsaKeys

def encrypt(message, args):
    message = bytes.fromhex(message)
    if (args.mode == Mode.GEN_RSA_KEY):
        publicKey, privateKey = genRsaKeys(args.P, args.Q)
        return "public key: " + publicKey + "\nprivate key: " + privateKey
    publicKey = args.key
    e = int.from_bytes(bytes.fromhex(publicKey.split("-")[0]), 'little')
    n = int.from_bytes(bytes.fromhex(publicKey.split("-")[1]), 'little')
    intToCipher = int.from_bytes(message, 'little')
    cipher = pow(intToCipher, e, n)
    return cipher.to_bytes((cipher.bit_length() + 7) // 8, 'little').hex()

def decrypt(message, args):
    message = bytes.fromhex(message)
    private_key = args.key
    d = int.from_bytes(bytes.fromhex(private_key.split("-")[0]), 'little')
    n = int.from_bytes(bytes.fromhex(private_key.split("-")[1]), 'little')
    intToPlain = int.from_bytes(message, 'little')
    plain = pow(intToPlain, d, n)
    return plain.to_bytes((plain.bit_length() + 7) // 8, 'little').hex()
