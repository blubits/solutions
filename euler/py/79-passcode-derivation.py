def determine_code(codes):
    graph = {}
    x = 0
    pairs = [(0, 1), (0, 2), (1, 2)]
    for code in codes:
        for a, b in pairs:
            if code[a] in graph:
                graph[code[a]].add(code[b])
            else:
                graph[code[a]] = set(code[b])
    outdegree = {}
    for node in graph:
        outdegree[node] = 0
        for nxt in graph[node]:
            if nxt not in outdegree:
                outdegree[nxt] = 0
            if node in outdegree:
                outdegree[node] += 1
            else:
                outdegree[node] = 1
    x = list(sorted(outdegree.items(), key=lambda x: x[1], reverse=True))
    return [t[0] for t in x]


with open("p079_keylog.txt") as infile:
    codes = [x.strip('\n') for x in infile.readlines()]
    x = determine_code(codes)
    print(x)
    for code in x:
        print(code, end='')
    print()
