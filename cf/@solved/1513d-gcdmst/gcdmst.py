class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return False
        if self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        elif self.rank[xroot] > self.rank[yroot]:
            self.parent[yroot] = xroot
        else:
            self.parent[yroot] = xroot
            self.rank[xroot] += 1
        return True

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def kruskal(n, edges):
    dsu = DisjointSetUnion(n)
    mst_weight = 0
    for weight, u, v in edges:
        if dsu.union(u, v):
            mst_weight += weight
    return mst_weight

t = int(input())
for _ in range(t):
    n, p = map(int, input().split())
    a = list(map(int, input().split()))
    edges = []

    # Add p-edges
    for i in range(n - 1):
        edges.append((p, i, i + 1))

    # Add GCD-edges
    for i in range(n):
        current_gcd = a[i]
        min_value = a[i]
        for j in range(i + 1, n):
            current_gcd = gcd(current_gcd, a[j])
            min_value = min(min_value, a[j])
            if current_gcd == min_value:
                edges.append((min_value, i, j))
            if current_gcd == 1:
                break

    # Sort edges by weight
    edges.sort()

    # Find MST using Kruskal's algorithm
    mst_weight = kruskal(n, edges)
    print(mst_weight)