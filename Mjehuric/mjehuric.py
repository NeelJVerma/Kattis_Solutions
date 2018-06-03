def print_steps(sequence):
    while sequence != [1, 2, 3, 4, 5]:
        for i in range(4):
            if sequence[i] > sequence[i + 1]:
                sequence[i], sequence[i + 1] = sequence[i + 1], sequence[i]

                for num in sequence:
                    print(num, end=' ')

                print()

sequence = [int(x) for x in input().split()]

print_steps(sequence)