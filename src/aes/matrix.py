
from src.aes.SBox import lookupSBox, lookupReverseSBox

class Word:
    def __init__(self) -> None:
        self.matrix = [0x00 for i in range(4)]

    def __getitem__(self, index: int) -> int:
        return self.matrix[index]

    def __setitem__(self, index: int, value: int) -> None:
        self.matrix[index] = value

    def __xor__(self, values: 'Word') -> 'Word':
        for i in range(4):
            self.matrix[i] ^= values[i]
        return self

    def __ixor__(self, values: 'Word') -> 'Word':
        return self ^ values

    def __lshift__(self, offset: int) -> 'Word':
        """
        Used for circular rotation part
        """
        self.matrix = self.matrix[offset:] + self.matrix[:offset]
        return self

    def __ilshift__(self, offset: int) -> 'Word':
        """
        Used for circular rotation part
        """
        return self << offset

    def __rshift__(self, offset: int) -> 'Word':
        """
        Used for reversed circular rotation part
        """
        return self << -offset

    def __irshift__(self, offset: int) -> 'Word':
        """
        Used for reversed circular rotation part
        """
        return self << -offset

    def __pos__(self) -> 'Word':
        """
        Used for substitution part
        """
        for i in range(4):
            self.matrix[i] = lookupSBox(self.matrix[i])
        return self

    def __neg__(self) -> 'Word':
        """
        Used for substitution part
        """
        for i in range(4):
            self.matrix[i] = lookupReverseSBox(self.matrix[i])
        return self

    def __repr__(self) -> str:
        return f"[{self.matrix[0]}, {self.matrix[1]}, {self.matrix[2]}, {self.matrix[3]}]"

    def copy(self) -> 'Word':
        newWord = Word()
        copy = list(self.matrix)
        for i in range(4):
            newWord[i] = copy[i]
        return newWord

    def hex(self):
        str = ""
        for i in range(0, 4):
            str += int(self.matrix[i]).to_bytes().hex()
        return str



class Matrix:
    def __init__(self, key: bytes = "") -> None:
        self.matrix = [Word() for i in range(4)]
        self.setValues(key)

    def __getitem__(self, index: int) -> Word:
        return self.matrix[index]

    def __setitem__(self, index: int, value: Word) -> None:
        self.matrix[index] = value

    def __xor__(self, values: 'Matrix') -> 'Matrix':
        for i in range(4):
            self.matrix[i] ^= values[i]
        return self

    def __ixor__(self, values: 'Matrix') -> 'Matrix':
        return self ^ values

    def __repr__(self) -> str:
        return f"{self.matrix[0]},\t{self.matrix[1]},\t{self.matrix[2]},\t{self.matrix[3]}"

    def setValues(self, values: bytes) -> None:
        if (len(values) != 16):
            return
        for x in range(4):
            for y in range(4):
                self.matrix[x][y] = values[x * 4 + y]

    def getMatrix(self) -> list[Word]:
        return self.matrix

    def getWord(self, index: int) -> Word:
        return self.matrix[index]


    def doSubBytes(self) -> None:
        for i in range(4):
            self.matrix[i] = +self.matrix[i]

    def doInvSubBytes(self) -> None:
        for i in range(4):
            self.matrix[i] = -self.matrix[i]

    def doShiftRows(self) -> None:
        for i in range(4):
            word = Word()
            for j in range(4):
                word[j] = self.matrix[j][i]
            word <<= i
            for j in range(4):
                self.matrix[j][i]= word[j]

    def doInvShiftRows(self) -> None:
        for i in range(4):
            word = Word()
            for j in range(4):
                word[j] = self.matrix[j][i]
            word >>= i
            for j in range(4):
                self.matrix[j][i]= word[j]

    def doMixColumns(self) -> None:
        for i in range(4):
            word = self.matrix[i].copy()
            self.matrix[i][0] = galoisMulti(word[0], 0x02) ^ galoisMulti(word[1], 0x03) ^ galoisMulti(word[2], 0x01) ^ galoisMulti(word[3], 0x01)
            self.matrix[i][1] = galoisMulti(word[0], 0x01) ^ galoisMulti(word[1], 0x02) ^ galoisMulti(word[2], 0x03) ^ galoisMulti(word[3], 0x01)
            self.matrix[i][2] = galoisMulti(word[0], 0x01) ^ galoisMulti(word[1], 0x01) ^ galoisMulti(word[2], 0x02) ^ galoisMulti(word[3], 0x03)
            self.matrix[i][3] = galoisMulti(word[0], 0x03) ^ galoisMulti(word[1], 0x01) ^ galoisMulti(word[2], 0x01) ^ galoisMulti(word[3], 0x02)

    def doInvMixColumns(self) -> None:
        for i in range(4):
            word = self.matrix[i].copy()
            self.matrix[i][0] = galoisMulti(word[0], 0x0e) ^ galoisMulti(word[1], 0x0b) ^ galoisMulti(word[2], 0x0d) ^ galoisMulti(word[3], 0x09)
            self.matrix[i][1] = galoisMulti(word[0], 0x09) ^ galoisMulti(word[1], 0x0e) ^ galoisMulti(word[2], 0x0b) ^ galoisMulti(word[3], 0x0d)
            self.matrix[i][2] = galoisMulti(word[0], 0x0d) ^ galoisMulti(word[1], 0x09) ^ galoisMulti(word[2], 0x0e) ^ galoisMulti(word[3], 0x0b)
            self.matrix[i][3] = galoisMulti(word[0], 0x0b) ^ galoisMulti(word[1], 0x0d) ^ galoisMulti(word[2], 0x09) ^ galoisMulti(word[3], 0x0e)

    def doAddRoundKey(self, key: 'Matrix') -> None:
        self ^= key

    def hex(self):
        str = ""
        for i in range(0, 4):
            str += self.matrix[i].hex()
        return str

def galoisMulti(value, multiplicator):
    """
    Multiplication in the Galois field GF(2^8).
    """
    ret = 0
    bitSet = 0

    for i in range(8):
        if (multiplicator & 1 == 1):
            ret ^= value
        bitSet = value & 0x80
        value <<= 1
        if (bitSet == 0x80):
            value ^= 0x1b
        multiplicator >>= 1
    return (ret % 256)
