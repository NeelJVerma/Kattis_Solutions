inputs = [int(x) for x in input().split()]
bobage = inputs[0]
bobretire = inputs[1]
bobsave = inputs[2]
aliceage = inputs[3]
alicesave = inputs[4]
bobtotal = (bobretire - bobage) * bobsave
alicetotal = 0
aliceyears = 0

while alicetotal <= bobtotal:
    alicetotal += alicesave
    aliceyears += 1

aliceretire = aliceage + aliceyears

print(aliceretire)