notes = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
L = len(notes)
scales = {note: [] for note in notes}

for i, note in enumerate(notes):
    scale = [notes[i], notes[(i + 2) % L], notes[(i + 4) % L], notes[(
        i + 5) % L], notes[(i + 7) % L], notes[(i + 9) % L], notes[(i + 11) % L]]
    for scalenote in scale:
        scales[scalenote].append(note)

for note, scale in scales.items():
    print("{0}, {1}".format(note, scale))
