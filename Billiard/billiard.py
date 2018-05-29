import math

while True:
    a, b, s, m, n = map(int, input().split())

    if a == b == s == m == n == 0:
        break

    xdist = a * m
    ydist = b * n
    totaldist = (xdist ** 2 + ydist ** 2) ** 0.5
    angle = 180 * math.acos(xdist / totaldist) / math.pi
    velocity = totaldist / s

    print('{0:0.2f} {1:0.2f}'.format(angle, velocity))