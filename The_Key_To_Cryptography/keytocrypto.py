cipher = str(input())
key = str(input())
cipherlength = len(cipher)
keylength = len(key)
minlength = cipherlength if cipherlength < keylength else keylength
indexone = indextwo = 0
original = [0 for i in range(cipherlength)]

for i in range(minlength):
    original[indexone] = chr(((ord(cipher[i]) - ord(key[i]) + 26) % 26) + 65)
    indexone += 1

for i in range(keylength, cipherlength):
    original[indexone] = chr(((ord(cipher[i]) - ord(original[indextwo]) + 26) % 26) + 65)
    indexone += 1
    indextwo += 1

print(''.join(original))