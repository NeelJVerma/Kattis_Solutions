numbers = {'**** ** ** ****': 0,
           '  *  *  *  *  *': 1,
           '***  *****  ***': 2,
           '***  ****  ****': 3,
           '* ** ****  *  *': 4,
           '****  ***  ****': 5,
           '****  **** ****': 6,
           '***  *  *  *  *': 7,
           '**** ***** ****': 8,
           '**** ****  ****': 9}

inputlist = ['' for i in range(10)]
size = int()

for i in range(5):
    line = str(input())
    size = len(line) // 4 + 1

    for j in range(size):
        inputlist[j] += line[j * 4: (j * 4) + 3]

total = 0
valid = True

for i in range(size):
    if inputlist[i] in numbers:
        total *= 10
        total += numbers[inputlist[i]]
    else:
        valid = False

        break

if valid and total % 6 == 0:
    print('BEER!!')
else:
    print('BOOM!!')