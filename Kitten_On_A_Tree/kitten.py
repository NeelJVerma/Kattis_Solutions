startbranch = int(input())
branches = {}
front = [-1] * 101

while True:
    branchdesc = [int(x) for x in input().split()]

    if branchdesc[0] == -1:
        break

    for num in branchdesc[1:]:
        front[num] = branchdesc[0]

print(startbranch, end=' ')

while front[startbranch] != -1:
    startbranch = front[startbranch]

    print(startbranch, end=' ')