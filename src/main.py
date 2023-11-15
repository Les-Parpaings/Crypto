
from src.args import Args,

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

    if (args.algo == )
