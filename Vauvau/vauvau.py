def is_angry(aggressive, calm, time):
    time -= 1

    return ((time % (aggressive + calm)) < aggressive)

def calculate_worker(a, b, c, d, time):
    count = 0
    
    if is_angry(a, b, time):
        count += 1

    if is_angry(c, d, time):
        count += 1

    if count == 0:
        return 'none'

    if count == 1:
        return 'one'

    return 'both'

a, b, c, d = map(int, input().split())
p, m, g = map(int, input().split())

print(calculate_worker(a, b, c, d, p))
print(calculate_worker(a, b, c, d, m))
print(calculate_worker(a, b, c, d, g))