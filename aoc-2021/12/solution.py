def parse(lines):
    adj_list = {}
    vertices = set()
    for line in lines:
        fr, to = line.split("-")
        if fr not in adj_list:
            adj_list[fr] = [to]
        else:
            adj_list[fr].append(to)
        if to not in adj_list:
            adj_list[to] = [fr]
        else:
            adj_list[to].append(fr)
        vertices.add(fr)
        vertices.add(to)
    return (adj_list, vertices)

def solve1(lines):
    adj_list, vertices = parse(lines)
    visited = {vertex: False for vertex in vertices}
    def count_paths(vertex):
        if vertex == "end":
            return 1
        if vertex == vertex.lower():
            visited[vertex] = True
        paths = 0
        for neighbor in adj_list[vertex]:
            if not visited[neighbor]:
                paths += count_paths(neighbor)
        visited[vertex] = False
        return paths
    return count_paths("start")


def solve2(lines):
    adj_list, vertices = parse(lines)
    visited = {vertex: 0 for vertex in vertices}
    path = []
    def count_paths(vertex, visited_twice):
        if vertex == "end":
            print(",".join(path) + ",end")
            return 1
        path.append(vertex)
        if vertex == vertex.lower():
            visited[vertex] += 1
        paths = 0
        for neighbor in adj_list[vertex]:
            if neighbor == "start": 
                continue
            if visited[neighbor] == 0:
                paths += count_paths(neighbor, visited_twice)
            if visited[neighbor] == 1 and not visited_twice:
                visited_twice = True
                paths += count_paths(neighbor, visited_twice)
                visited_twice = False
        if vertex == vertex.lower():
            visited[vertex] -= 1
        path.pop()
        return paths
    return count_paths("start", False)


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
