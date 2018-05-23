from math import sqrt

def distance(x, y):
    return sqrt(((x[0] - y[0]) ** 2) + ((x[1] - y[1]) ** 2))


points = int(input())
coordinates = []
tour = list(range(points))
used = {i: False for i in range(points)}
used[0] = True

for i in range(points):
    string = str(input())
    xylist = string.split()
    x = float(xylist[0])
    y = float(xylist[1])

    coordinates.append((x, y))

for i in range(1, points):
    best = -1

    for j in range(points):
        distanceone = distance(coordinates[tour[i - 1]], coordinates[j])
        distancetwo = distance(coordinates[tour[i - 1]], coordinates[best])

        if not used[j] and (best == -1 or distanceone < distancetwo):
            best = j

    tour[i] = best
    used[best] = True

for i in range(points):
    print(tour[i])