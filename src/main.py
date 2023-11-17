from src.args import Args
from src.rsa.generateKeys import genRsaKeys
from src.rsa.logic import decrypt

    # test rsa decrypt
    # p = "4b1da73924978f2e9c1f04170e46820d648edbee12ccf4d4462af89b080c86e1"
    # q = "bb3ca1e126f7c8751bd81bc8daa226494efb3d128f72ed9f6cacbe96e14166cb"
    # publicKey, privateKey = genRsaKeys(int.from_bytes(bytes.fromhex(p), 'little'), int.from_bytes(bytes.fromhex(q), 'little'))
    # print(f"Public key: {publicKey}")
    # print(f"Private key: {privateKey}")
    # args = Args()
    # args.key = privateKey
    # message = "dc0bd7367d04e5a9e9e14467ff38de0625b3cfa5aabbe86def48bfc93e97aab713d70abf83d263a6dd6570c6d297cc44bad2e0dd2cf7b4c3e0a9749d68ca11a8"
    # print(decrypt(bytes.fromhex(message), args))

    # test rsa encrypt
    # p = "4b1da73924978f2e9c1f04170e46820d648edbee12ccf4d4462af89b080c86e1"
    # q = "bb3ca1e126f7c8751bd81bc8daa226494efb3d128f72ed9f6cacbe96e14166cb"
    # publicKey, privateKey = genRsaKeys(int.from_bytes(bytes.fromhex(p), 'little'), int.from_bytes(bytes.fromhex(q), 'little'))
    # print(f"Public key: {publicKey}")
    # print(f"Private key: {privateKey}")
    # args = Args()
    # args.key = publicKey
    # message = "c1fa29d40054f3fcb1c15fe4d63d3887"
    # print(encrypt(bytes.fromhex(message), args))

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
