numnotes = int(input())
notesequence = set(input().split())
jumps = [2, 4, 5, 7, 9, 11, 12]
notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
scales = {notes[i]: {notes[(i + j) % len(notes)] for j in jumps}
          for i in range(len(notes))}
validscales = ' '.join(filter(lambda x: notesequence.issubset(scales[x]),
                                                              notes))
print(validscales if validscales else 'none')