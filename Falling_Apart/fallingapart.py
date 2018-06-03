numpieces = int(input())
pieces = reversed(sorted([int(x) for x in input().split()]))
alice = 0
bob = 0
i = 0

for num in pieces:
    if i & 1 == 1:
        bob += num
    else:
        alice += num

    i += 1

print(alice, bob)