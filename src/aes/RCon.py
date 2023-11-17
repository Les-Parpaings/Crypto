
def getRCon():
    RCon = [[1, 0, 0, 0]]

    for _ in range(1, 11):
        RCon.append([RCon[-1][0] * 2, 0, 0, 0])
        if (RCon[-1][0] > 0x80):
            RCon[-1][0] ^= 0x11b

    return RCon
