firstthree = [int(x) for x in input().split()]
secondthree = [int(x) for x in input().split()]
thirdthree = [int(x) for x in input().split()]
matrix = [firstthree, secondthree, thirdthree]
nums = {}

for i in range(3):
    for j in range(3):
        nums[matrix[i][j]] = (i, j)

length = 0

for i in range(2, 10):
    coordone = nums[i]
    coordtwo = nums[i - 1]

    if abs(coordone[0] - coordtwo[0]) == 2 and abs(coordone[1] - coordtwo[1]) == 2:
        length += (8 ** 0.5)
    elif abs(coordone[0] - coordtwo[0]) == 1 and abs(coordone[1] - coordtwo[1]) == 1:
        length += (2 ** 0.5)
    elif ((abs(coordone[0] - coordtwo[0]) == 2 and abs(coordone[1] - coordtwo[1]) == 1) or
          (abs(coordone[0] - coordtwo[0]) == 1 and abs(coordone[1] - coordtwo[1]) == 2)):
        length += (5 ** 0.5)
    elif ((abs(coordone[0] - coordtwo[0]) == 2 and abs(coordone[1] - coordtwo[1]) == 0) or
          (abs(coordone[0] - coordtwo[0]) == 0 and abs(coordone[1] - coordtwo[1]) == 2)):
        length += 2
    else:
        length += 1

print(length)