
from src.aes.matrix import Matrix, Word

def getRCon() -> list[Word]:
    RCon = [Word() for i in range(11)]
    RCon[0][0] = 1

    for i in range(1, 11):
        RCon[i][0] = RCon[i - 1][0] * 2
        if (RCon[i][0] > 0x80):
            RCon[i][0] ^= 0x11b

    return RCon
