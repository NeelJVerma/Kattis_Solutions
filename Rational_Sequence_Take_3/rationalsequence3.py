def compute_nth(n):
    goal = n
    path = [goal]

    while goal > 1:
        goal //= 2
        path.append(goal)

    p = q = 1

    for i in range(len(path) - 2, -1, -1):
        if path[i] & 1 == 1:
            q += p
        else:
            p += q

    return (q, p)

test = int(input())

for i in range(test):
    testnum, n = map(int, input().split())
    nth = compute_nth(n)

    print('{0} {1}/{2}'.format(testnum, nth[0], nth[1]))