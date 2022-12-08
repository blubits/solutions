with open("input") as input_file:
    text = input_file.readlines()[0].rstrip()
    for i in range(len(text) - 14):
        if len(set(text[i:i+14])) == 14:
            print(text[i:i+14], i+14)
            break