
from src.args import Mode, Algorithm, Args
from src.aes.matrix import Matrix, Word
from src.aes.key import genereateAllKeys

def encrypt(message: bytes, args: Args) -> str:
    allKeys = genereateAllKeys(bytes.fromhex(args.key))

    matrix = Matrix()
    matrix.setValues(message)
    matrix.doAddRoundKey(allKeys[0])

    for i in range(1, 10):
        matrix.doSubBytes()
        matrix.doShiftRows()
        matrix.doMixColumns()
        matrix.doAddRoundKey(allKeys[i])

    matrix.doSubBytes()
    matrix.doShiftRows()
    matrix.doAddRoundKey(allKeys[10])

    return matrix.hex()

def decrypt(message, args) -> str:
    allKeys = genereateAllKeys(bytes.fromhex(args.key))

    matrix = Matrix()
    matrix.setValues(message)
    matrix.doAddRoundKey(allKeys[10])

    for i in range(1, 10):
        matrix.doInvShiftRows()
        matrix.doInvSubBytes()
        matrix.doAddRoundKey(allKeys[10 - i])
        matrix.doInvMixColumns()

    matrix.doInvShiftRows()
    matrix.doInvSubBytes()
    matrix.doAddRoundKey(allKeys[0])

    return matrix.hex()
