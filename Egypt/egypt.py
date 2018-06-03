from math import acos, degrees

while True:
    a, b, c = map(int, input().split())

    if a == b == c == 0:
        break

    tocheck = ((a ** 2) + (b ** 2) == (c ** 2) or
               (b ** 2) + (c ** 2) == (a ** 2) or
               (c ** 2) + (a ** 2) == (b ** 2))

    print('right' if tocheck else 'wrong')