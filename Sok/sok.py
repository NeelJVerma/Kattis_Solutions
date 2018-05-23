bought = [int(x) for x in input().split()]
calledfor = [int(x) for x in input().split()]
ratios = [bought[i] / calledfor[i] for i in range(len(bought))]
minratio = min(ratios)
leftover = [bought[i] - (calledfor[i] * minratio) for i in range(len(bought))]

for left in leftover:
    print(left, end=' ')