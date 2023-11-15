
from src.args import Args, Algorithm, Mode

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

    message = ""
    if (args.algo != Algorithm.RSA and args.mode != Mode.GEN_RSA_KEY):
        message = int.from_bytes(bytes.fromhex(input()), "little")

    print(message)
