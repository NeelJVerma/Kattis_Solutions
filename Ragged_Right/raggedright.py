from sys import stdin

maxline = 0
raggedness = 0
lines = []

for line in stdin:
    if len(line) > maxline:
        maxline = len(line)

    lines.append(line)

for i in range(len(lines) - 1):
    raggedness += ((maxline - len(lines[i])) ** 2)

print(raggedness)