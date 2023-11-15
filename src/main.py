
from src.args import Args

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

    print(f"args.mode: {args.mode}")
    print(f"args.algo: {args.algo}")
    print(f"args.help: {args.help}")
    print(f"args.block: {args.block}")
    print(f"args.P: {args.P}")
    print(f"args.Q: {args.Q}")
    print(f"args.key: {args.key}")
