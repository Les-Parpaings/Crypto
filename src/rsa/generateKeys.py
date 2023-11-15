from math import gcd

def calculateE(lambdaVar):
    e = 65537
    while gcd(e, lambdaVar) != 1 and e < lambdaVar:
        e += 2
    return e

def calculateD(e, lambdaVar):
    k = 1
    d = (1 + k * lambdaVar) // e
    while (d * e) % lambdaVar != 1:
        d = (1 + k * lambdaVar) // e
        k += 1
    return d

def genRsaKey(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    lambdaVar = phi // gcd(p - 1, q - 1)
    e = calculateE(lambdaVar)
    d = calculateD(e, lambdaVar)
    publicKey = e.to_bytes((e.bit_length() + 7) // 8, 'little').hex().rstrip("0")+ "-" + n.to_bytes((n.bit_length() + 7) // 8, 'little').hex().rstrip("0")
    privateKey = d.to_bytes((d.bit_length() + 7) // 8, 'little').hex().rstrip("0") + "-" + n.to_bytes((n.bit_length() + 7) // 8, 'little').hex().rstrip("0")
    return publicKey, privateKey

# def encrypt(message, publicKey):
#     e, n = publicKey.split("-")
#     e = int.from_bytes(bytes.fromhex(e), "little")
#     n = int.from_bytes(bytes.fromhex(n), "little")
#     message = int.from_bytes(message.encode(), "little")
#     return pow(message, e, n)
