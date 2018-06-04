from sys import stdin

factorials = {0: 1}

for i in range(1, 101):
    factorials[i] = factorials[i - 1] * i

def count_anagrams(string):
    chars = {}

    for char in string:
        if ord(char) not in chars:
            chars[ord(char)] = 1
        else:
            chars[ord(char)] += 1

    result = factorials[len(string) - 1]

    for char in chars:
        result //= factorials[chars[char]]

    return result

for line in stdin:
    print(count_anagrams(line))