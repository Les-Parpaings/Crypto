
from src.aes.RCon import getRCon
from src.aes.SBox import lookupSBox, lookupReverseSBox

class Word:
    def __init__(self) -> None:
        self.matrix = [0x00 for i in range(4)]

    def __getitem__(self, index: int) -> int:
        return self.matrix[index]

    def __setitem__(self, index: int, value: int) -> None:
        self.matrix[index] = value

    def __xor__(self, values: list[int]):
        if (len(values) != 4):
            return self
        for i in range(4):
            self.matrix[i] ^= values[i]
        return self

    def __ixor__(self, values: list[int]):
        return self ^ values

    def __lshift__(self, index: int):
        """
        Used for circular rotation part
        """
        self.matrix = self.matrix[index:] + self.matrix[:index]
        return self

    def __ilshift__(self, offset: int):
        """
        Used for circular rotation part
        """
        return self << offset

    def __rshift__(self, index: int):
        """
        Used for reversed circular rotation part
        """
        self.matrix = self.matrix[:index] + self.matrix[index:]
        return self

    def __irshift__(self, offset: int):
        """
        Used for reversed circular rotation part
        """
        return self >> offset

    def __pos__(self):
        """
        Used for substitution part
        """
        for i in range(4):
            self.matrix[i] = lookupSBox(self.matrix[i])
        return self

    def __neg__(self):
        """
        Used for substitution part
        """
        for i in range(4):
            self.matrix[i] = lookupReverseSBox(self.matrix[i])
        return self

    def __repr__(self) -> str:
        return f"[{self.matrix[0]}, {self.matrix[1]}, {self.matrix[2]}, {self.matrix[3]}]"

    def copy(self):
        newWord = Word()
        copy = list(self.matrix)
        for i in range(4):
            newWord[i] = copy[i]
        return newWord

class Key:
    def __init__(self, key: bytes = ""):
        self.matrix = [Word() for i in range(4)]
        self.setValues(key)

    def __getitem__(self, index: int):
        return self.matrix[index]

    def __setitem__(self, index: int, value: Word):
        self.matrix[index] = value

    def __repr__(self) -> str:
        return f"{self.matrix[0]},\t{self.matrix[1]},\t{self.matrix[2]},\t{self.matrix[3]}"

    def setValues(self, values: bytes):
        if (len(values) != 16):
            return
        for x in range(4):
            for y in range(4):
                self.matrix[x][y] = values[x * 4 + y]

    def getMatrix(self):
        return self.matrix

    def getWord(self, index: int):
        return self.matrix[index]

def getValueFromLastWord(word: Word, RCon: list[int]) -> Word:
    lastWord = word.copy()
    wordShift = (lastWord << 1)
    wordSub = +wordShift
    wordRCon = wordSub ^ RCon
    return wordRCon

def genereateAllKeys(keyOriginal: bytes) -> list[Key]:
    RCon = getRCon()

    allKeys = [Key() for i in range(11)]
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
