def is_ostgotska(string):
    count = 0
    stringlist = string.split()

    for word in stringlist:
        if word.find('ae') != -1:
            count += 1

    percentage = count / len(stringlist)

    return ('dae ae ju traeligt va' if percentage * 100 >= 40.0 else
            'haer talar vi rikssvenska')

string = str(input())
print(is_ostgotska(string))