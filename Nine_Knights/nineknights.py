movex = [-2, -1, 1, 2, 2, 1, -1, -2]
movey = [-1, -2, -2, -1, 1, 2, 2, 1]

def is_knight_valid(matrix, i, j):
    for idx in range(8):
        x = i + movex[idx]
        y = j + movey[idx]

        if movex[idx] < 0 and movey[idx] < 0:
            if x >= 0 and y >= 0:
                if matrix[x][y] == 'k':
                    return False
        elif movex[idx] > 0 and movey[idx] < 0:
            if x < 5 and y >= 0:
                if matrix[x][y] == 'k':
                    return False
        elif movex[idx] > 0 and movey[idx] > 0:
            if x < 5 and y < 5:
                if matrix[x][y] == 'k':
                    return False
        elif movex[idx] < 0 and movey[idx] > 0:
            if x >= 0 and y < 5:
                if matrix[x][y] == 'k':
                    return False

    return True

def is_board_valid(matrix):
    count = 0

    for i in range(5):
        for j in range(5):
            if matrix[i][j] == 'k':
                if is_knight_valid(matrix, i, j):
                    count += 1

    return count == 9

matrix = []

for i in range(5):
    matrix.append(str(input()))

if is_board_valid(matrix):
    print('valid')
else:
    print('invalid')