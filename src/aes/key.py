
from src.aes.matrix import Matrix, Word
from src.aes.RCon import getRCon

def getValueFromLastWord(word: Word, RCon: Word) -> Word:
    lastWord = word.copy()
    wordShift = (lastWord << 1)
    wordSub = +wordShift
    wordRCon = wordSub ^ RCon
    return wordRCon

def genereateAllKeys(keyOriginal: bytes) -> list[Matrix]:

    if (len(keyOriginal) != 16):
        raise("key size is different from 16 bytes")

    RCon = getRCon()

    allKeys = [Matrix() for i in range(11)]
    allKeys[0].setValues(keyOriginal)

    for indexKey in range(1, 11):
        key = allKeys[indexKey]
        prevKey = allKeys[indexKey - 1]

        for indexWord in range(4):
            if indexWord == 0:
                toXor = getValueFromLastWord(prevKey[3], RCon[indexKey - 1])
            else:
                toXor = key[indexWord - 1]

            for indexByte in range(4):
                key[indexWord][indexByte] = prevKey[indexWord][indexByte] ^ toXor[indexByte]

    return allKeys
