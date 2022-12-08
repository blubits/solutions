def bachet(base, choices):
    results_dict = {x: 1 for x in range(1, base)}
    for x in results_dict.keys():
        if x == 0:
            continue
        for y in choices:
            if x + y in results_dict:
                results_dict[x + y] *= 0
            else:
                results_dict[x + y] = 0
    return results_dict[base]

def main():
    try:
        while True:
            entry = list(map(int, input().split()))
            root, div_list = entry[0], sorted(entry[2:])[::-1]
            print(bachet(root, div_list))
    except EOFError:
        return 0

main()
