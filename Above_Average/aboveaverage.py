def get_average(scores):
    return sum(scores) / len(scores)

def percentage_above_average(scores):
    average = get_average(scores)
    count = 0

    for score in scores:
        if score > average:
            count += 1

    return count / len(scores) * 100

test = int(input())

for i in range(test):
    scores = [int(x) for x in input().split()][1:]

    print('{0:.3f}%'.format(percentage_above_average(scores)))