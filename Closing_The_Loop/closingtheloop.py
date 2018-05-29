test = int(input())

for i in range(test):
    segments = int(input())
    ropes = [str(x) for x in input().split()]
    reds = sorted([int(rope[:rope.find('R')]) for rope in ropes if rope.find('R') != -1], reverse=True)
    blues = sorted([int(rope[:rope.find('B')]) for rope in ropes if rope.find('B') != -1], reverse=True)
    length = 0
    touse = len(reds) if len(reds) < len(blues) else len(blues)

    for j in range(touse):
        if not reds[j] or not blues[j]:
            break

        length += reds[j] + blues[j] - 2

    print('Case #{0}: {1}'.format(i + 1, length))