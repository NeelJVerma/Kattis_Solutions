from sys import stdin

morse = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
         'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
         'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
         'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
         'Y': '-.--', 'Z': '--..', '_': '..--', '.': '---.', ',': '.-.-', '?': '----'}
letters = {}

for key in morse:
    letters[morse[key]] = key

def convert_to_morse(string):
    return (''.join([morse[char] for char in string]), 
            [len(morse[char]) for char in string])

def reverse_numbers(string):
    encoded, numbers = convert_to_morse(string)
    reversednumbers = []
    
    for num in reversed(numbers):
        reversednumbers.append(num)
    
    return encoded, reversednumbers

def decode(string):
    encoded, reversednumbers = reverse_numbers(string)
    count = 0
    pointer = 0
    number = reversednumbers[pointer]
    ret = []

    for number in reversednumbers:
        ret.append(encoded[pointer: pointer + number])

        pointer += number

    return ''.join([letters[code] for code in ret])

for line in stdin:
    line = line.strip('\n')
    print(decode(line))