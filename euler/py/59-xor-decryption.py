def xor_decrypt(message, key):
    i = 0
    decoded = []
    for letter in message:
        decoded.append(letter ^ key[i])
        i = (i + 1) % 3
    return decoded

def decrypt(message):
    lb = ord('a')
    ub = ord('z') + 1
    for i in range(lb, ub):
        for j in range(lb, ub):
            for k in range(lb, ub):
                ans = xor_decrypt(message, [i, j, k])
                string = ''.join([chr(x) for x in ans])
                if ' and ' in string.lower():
                    return ans

with open("p059_cipher.txt") as infile:
    message = [int(x) for x in infile.readline().split(',')]
    decrypted = decrypt(message)
    for letter in decrypted:
        print(chr(letter), end='')
    print()
    print(sum(decrypted))
