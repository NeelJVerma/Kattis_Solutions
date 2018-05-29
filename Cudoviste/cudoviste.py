r, c = map(int, input().split())
matrix = []

for i in range(r):
    matrix.append(list(str(input())))

zero = 0
one = 0
two = 0
three = 0
four = 0

for i in range(1, r):
    for j in range(1, c):
        current = matrix[i][j]
        up = matrix[i - 1][j]
        left = matrix[i][j - 1]
        diagonal = matrix[i - 1][j - 1]
        positions = [current, up, left, diagonal]

        if '#' in positions:
            continue

        cars = positions.count('X')

        if cars == 0:
            zero += 1

        if cars == 1:
            one += 1

        if cars == 2:
            two += 1

        if cars == 3:
            three += 1

        if cars == 4:
            four += 1

print(zero)
print(one)
print(two)
print(three)
print(four)