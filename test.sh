#!/bin/bash

ARG=$1      # -b
ALGO=$2     # -xor, -aes, -rsa, -pgp
MSG=$3      # in hex
KEY=$4      # in hex

CIPHERED=$(./mypgp $ALGO $ARG -c $KEY <<< $MSG)
RESULT=$(./mypgp $ALGO $ARG -d $KEY <<< $CIPHERED)

echo -e "key:\t\t${KEY}"
echo -e "message:\t${MSG}"
echo -e ""
echo -e "ciphered:\t${CIPHERED}"
echo -e "result:\t\t${RESULT}"
echo -e ""

if [[ "$MSG" == "$RESULT" ]]; then
    echo -e "Message was encrypt and decrypt correctly"
else
    echo -e "Message was encrypt and decrypt wrongly"
fi

# ∼/B-CNA-500> cat message | ./mypgp -xor -c -b 7665727920736563726574 > ciphered
# ∼/B-CNA-500> cat ciphered
# 1e001e154f53120c000910
# ∼/B-CNA-500> cat ciphered | ./mypgp -xor -d -b 7665727920736563726574
# 68656c6c6f20776f726c64
