t = int(input())

for i in range(t):
    x, y = map(int, input().split())
    a = (x + y) / 6
    b = ((x ** 2 + y ** 2 - x * y) ** 0.5) / 6
    h = a + b

    if not 0 < h < min(x, y) / 2:
        h = a - b

    print(h * (x - 2 * h) * (y - 2 * h))