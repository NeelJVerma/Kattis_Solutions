def gcd(a, b):
    a, b = max(a, b), min(a, b)

    while b:
        a, b = b, a % b

    return a

numrings = int(input())
radii = [int(i) for i in input().split()]

for i in range(len(radii) - 1):
    ratio = gcd(radii[0], radii[i + 1])

    print('{0}/{1}'.format(radii[0] // ratio, radii[i + 1] // ratio))