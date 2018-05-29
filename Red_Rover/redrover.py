def get_all_perms(string):
    perms = []

    for i in range(len(string)):
        for j in range(i + 1, len(string) + 1):
            perms.append(string[i: j])

    return perms

string = str(input())
lengthstring = len(string)

for s in get_all_perms(string):
    count = string.count(s)
    length = len(string) - count * (len(s) - 1) + len(s)

    if length < lengthstring:
        lengthstring = length

print(lengthstring)