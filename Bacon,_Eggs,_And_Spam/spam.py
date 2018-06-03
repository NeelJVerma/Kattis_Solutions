while True:
    numcustomers = int(input())

    if numcustomers == 0:
        break

    foodsdict = {}

    for i in range(numcustomers):
        string = str(input())
        stringsplit = string.split()
        customer = stringsplit[0]
        foods = stringsplit[1:]

        for food in foods:
            if food in foodsdict:
                foodsdict[food].append(customer)
            else:
                foodsdict[food] = [customer]

    for food in sorted(foodsdict):
        print(food, ' '.join(sorted(foodsdict[food])))