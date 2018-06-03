from sys import stdin

notes = {'A#': 'Bb', 'C#': 'Db', 'D#': 'Eb', 'F#': 'Gb', 'G#': 'Ab'}
notesreverse = {y: x for x, y in notes.items()}
case = 1

for line in stdin:
    splits = line.split()
    note = splits[0]
    key = splits[1]

    if note in notes:
        print('Case {0}: {1} {2}'.format(case, notes[note], key))
    elif note in notesreverse:
        print('Case {0}: {1} {2}'.format(case, notesreverse[note], key))
    else:
        print('Case {0}: UNIQUE'.format(case))

    case += 1