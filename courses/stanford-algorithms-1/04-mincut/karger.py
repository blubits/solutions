import random


class DisjointSet:

    def __init__(self, sz: int):
        self.sz = sz
        self.parent = list(range(sz))
        self.rank = [1] * sz

    def reset(self):
        self.parent = list(range(self.sz))
        self.rank = [1] * self.sz

    def union(self, i: int, j: int):
        i = self.parent[i]
        j = self.parent[j]

        if i == j:
            return  # i and j are already in the same set

        if self.rank[i] < self.rank[j]:
            i, j = j, i

        self.parent[j] = i
        if self.rank[i] == self.rank[j]:
            self.rank[i] += 1

    def find(self, i: int):
        while self.parent[i] != i:
            i, self.parent[i] = self.parent[i], self.parent[self.parent[i]]
        return i


def karger(graph: dict, edges: list):
    n = len(graph)
    ans = 1000000
    repeats = 6 * (n * (n - 1)) // 2
    dj = DisjointSet(n)
    for _ in range(repeats):
        random.seed()
        vertices = n
        cut_edges = 0
        dj.reset()
        while vertices > 2:
            #edge = edges[random.randint(0, len(edges) - 1)]
            edge = random.choice(edges)
            if dj.find(edge[0]) != dj.find(edge[1]):
                vertices -= 1
                dj.union(edge[0], edge[1])
        for edge in edges:
            if dj.find(edge[0]) != dj.find(edge[1]):
                cut_edges += 1
        if cut_edges < ans:
            print("Iteration {0}: {1}".format(_, cut_edges))
            ans = cut_edges
    return ans


if __name__ == "__main__":
    graph = {int(line[0]) - 1: [int(x) - 1 for x in line[1:]]
             for line in [x.split() for x in open("kargerMinCut.txt").readlines()]}
    edges = []
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            if (neighbor, node) not in edges:
                edges.append((node, neighbor))
    a = 100000
    while True:
        a = min(a, karger(graph, edges))
        print("New minimum: {0}".format(a))
