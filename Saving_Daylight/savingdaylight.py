from sys import stdin

for line in stdin:
    datetime = line.split()
    timeone = datetime[3]
    timetwo = datetime[4]
    colonone = timeone.find(':')
    hourone = int(timeone[:colonone])
    minuteone = int(timeone[colonone + 1:])
    colontwo = timetwo.find(':')
    hourtwo = int(timetwo[:colontwo])
    minutetwo = int(timetwo[colontwo + 1:])
    hourdiff = (hourtwo - hourone) % 24
    minutediff = minutetwo - minuteone

    if minutediff < 0:
        hourdiff -= 1

    minutediff %= 60

    print(datetime[0], datetime[1], datetime[2], hourdiff, 'hours', minutediff, 'minutes')