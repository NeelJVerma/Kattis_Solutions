num = int(input())
sequence = [int(x) for x in input().split()]
sub = [sequence[0]]

for i in range(1, len(sequence)):
    if sequence[i] > sub[len(sub) - 1]:
        sub.append(sequence[i])

print(len(sub))

for n in sub:
    print(n, end=' ')