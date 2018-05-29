import math

numtriangles = int(input())
triangles = []

for i in range(numtriangles):
    triangles.append(tuple([int(x) for x in input().split()]))

length = 0

for triangle in triangles:
    a = triangle[0]
    b = triangle[1]
    c = triangle[2]
    anglea = (b ** 2 + c ** 2 - a ** 2) / (2 * b * c)
    anglea = math.degrees(math.acos(anglea))
    angleb = (c ** 2 + a ** 2 - b ** 2) / (2 * c * a)
    angleb = math.degrees(math.acos(angleb))
    anglec = 180 - (anglea + angleb)
    area = ((1 / 2) * a * c * math.sin(math.radians(angleb)))
    medianc = ((2 * (a ** 2 + b ** 2) - c ** 2) ** 0.5)
    length += 2 * area / medianc

length *= 2

print(length)