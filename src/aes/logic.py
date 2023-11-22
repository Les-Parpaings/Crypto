
from src.args import Mode, Algorithm, Args
from src.aes.args import parseMessage
from src.aes.matrix import Matrix, Word
from src.aes.key import genereateAllKeys

def encrypt(message: bytes, args: Args) -> str:
    allKeys = []
    data = []
    dataToRet = ""

    try:
        allKeys = genereateAllKeys(bytes.fromhex(args.key))
        data = parseMessage(message, args)
    except ValueError as e:
        print(f"Error: {e}")
        exit(84)

    for i in range(len(data)):
        matrix = Matrix()
        matrix.setValues(data[i])
        matrix.doAddRoundKey(allKeys[0])

        for j in range(1, 10):
            matrix.doSubBytes()
            matrix.doShiftRows()
            matrix.doMixColumns()
            matrix.doAddRoundKey(allKeys[j])

        matrix.doSubBytes()
        matrix.doShiftRows()
        matrix.doAddRoundKey(allKeys[10])

        dataToRet += matrix.hex()

    return dataToRet

def decrypt(message: bytes, args: Args) -> str:
    allKeys = []
    data = []
    dataToRet = ""

    try:
        allKeys = genereateAllKeys(bytes.fromhex(args.key))
        data = parseMessage(message, args)
    except ValueError as e:
        print(f"Error: {e}")
        exit(84)

    for i in range(len(data)):
        matrix = Matrix()
        matrix.setValues(data[i])
        matrix.doAddRoundKey(allKeys[10])

        for j in range(1, 10):
            matrix.doInvShiftRows()
            matrix.doInvSubBytes()
            matrix.doAddRoundKey(allKeys[10 - j])
            matrix.doInvMixColumns()

        matrix.doInvShiftRows()
        matrix.doInvSubBytes()
        matrix.doAddRoundKey(allKeys[0])

        dataToRet += matrix.hex()

    return dataToRet
