problems, tests = map(int, input().split())
solved = 0

for i in range(problems):
    test = [input().strip() for i in range(tests)]

    if all(t[0].lower() + t[1:] == t.lower() for t in test):
        solved += 1

print(solved)