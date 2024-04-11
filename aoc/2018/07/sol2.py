from heapq import heappop, heappush, heapify

def toposort(graph):
    # find all nodes
    nodes = set()
    for node in graph:
        nodes.add(node)
        for next in graph[node]:
            nodes.add(next)
    indegree = {node: 0 for node in nodes}
    for node in graph:
        for next in graph[node]:
            indegree[next] += 1
    starting = []
    for node in indegree:
        if indegree[node] == 0:
            starting.append(node)
    heapify(starting)
    toponodes = []
    while starting:
        n = heappop(starting)
        toponodes.append(n)
        for next in graph.get(n, set()):
            indegree[next] -= 1
            if indegree[next] == 0:
                heappush(starting, next)
    return toponodes

def critical_path(graph):
    # find all nodes
    nodes = set()
    for node in graph:
        nodes.add(node)
        for next in graph[node]:
            nodes.add(next)
    # set their distances


with open("input.txt") as input_file:
    lines = input_file.readlines()
    graph = {}
    for line in lines:
        l = line.split()
        pre, post = l[1], l[7]
        if pre not in graph:
            graph[pre] = {post}
        else:
            graph[pre].add(post)
    print(toposort(graph))
