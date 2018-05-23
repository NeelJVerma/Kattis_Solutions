numgroups = int(input())

for i in range(numgroups):
    group = [int(x) for x in input().split()]
    group.pop(0)

    king = 0

    for j in range(len(group) - 2):
        a = group[j]
        b = group[j + 1]
        c = group[j + 2]

        if a < c and (a < b and b > c):
            king = j + 2

            break

        if a < c and (a > b and b < c):
            king = j + 2

            break

    print(king)