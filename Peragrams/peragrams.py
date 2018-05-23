string = str(input())
numodd = 0
letters = {}

for char in string:
    if char not in letters:
        letters[char] = 1
    else:
        letters[char] += 1

for letter in letters:
    if letters[letter] & 1 == 1:
        numodd += 1

if numodd == 0:
    print(0)
else:
    print(numodd - 1)