# TODO: optimize better, figure out the correct solution that runs in less than 15 seconds

import queue


def parse(lines):
    flow_rate = {}
    adj_graph = {}
    start_valve = "AA"
    for line in lines:
        line = (
            line.replace("Valve ", "")
            .replace(" has flow rate=", ",")
            .replace("; tunnels lead to valves", ",")
            .replace("; tunnel leads to valve ", ",")
        )
        valve, fr, *next_valves = line.split(",")
        next_valves = [valve.strip() for valve in next_valves]
        fr = int(fr)
        flow_rate[valve] = fr
        adj_graph[valve] = next_valves
    return flow_rate, adj_graph, start_valve


def shortest_path(adj_graph, fr, vertices):
    to = {}
    answer = {"distance": 0, "path": []}
    visited = set()
    q = queue.Queue()
    q.put((fr, 0, []))
    visited.add(fr)
    while not q.empty():
        v, distance, path = q.get()
        if v in vertices:
            to[v] = {"distance": distance, "path": path.copy()}
        for w in adj_graph[v]:
            if w not in visited:
                visited.add(w)
                vw_path = path.copy()
                vw_path.append(w)
                q.put((w, distance + 1, vw_path))
    return to


def dfs(
    curr_vertex, curr_time, path, visited, adj_graph, num_vertices, max_time, flow_rate
):
    visited.add(curr_vertex)
    if curr_time > max_time or len(visited) == num_vertices:
        # calculate total pressure
        total_flow_rate = sum(
            [
                (max_time - curr_time) * flow_rate[vertex]
                for vertex, curr_time in path
                if curr_time < 30
            ]
        )
        # print(path, total_flow_rate)
        visited.remove(curr_vertex)
        return total_flow_rate
    max_total_pressure = 0
    for neighbor in adj_graph[curr_vertex]:
        if neighbor not in visited:
            max_total_pressure = max(
                max_total_pressure,
                dfs(
                    neighbor,
                    curr_time + adj_graph[curr_vertex][neighbor]["distance"] + 1,
                    path
                    + [
                        (
                            neighbor,
                            curr_time
                            + adj_graph[curr_vertex][neighbor]["distance"]
                            + 1,
                        )
                    ],
                    visited,
                    adj_graph,
                    num_vertices,
                    max_time,
                    flow_rate,
                ),
            )
    visited.remove(curr_vertex)
    return max_total_pressure


def dfs2(
    curr_vertex,
    curr_time,
    path,
    visited,
    adj_graph,
    num_vertices,
    max_time,
    flow_rate,
    is_elephant,
):
    if visited != "AA":
        visited.add(curr_vertex)
    if curr_time > max_time or len(visited) == num_vertices:
        if not is_elephant:
            if curr_time > max_time:
                actual_visited = visited - {curr_vertex}
            else:
                actual_visited = visited
            total_flow_rate = dfs2(
                "AA",
                0,
                [],
                actual_visited,
                adj_graph,
                num_vertices,
                max_time,
                flow_rate,
                not is_elephant,
            )
        else:
            total_flow_rate = 0
        total_flow_rate += sum(
            [
                (max_time - curr_time) * flow_rate[vertex]
                for vertex, curr_time in path
                if curr_time < 30
            ]
        )
        # print("el" if is_elephant else "me+el", path, total_flow_rate)
        visited.remove(curr_vertex)
        return total_flow_rate
    max_total_pressure = 0
    for neighbor in adj_graph[curr_vertex]:
        if neighbor != "AA" and neighbor not in visited:
            max_total_pressure = max(
                max_total_pressure,
                dfs2(
                    neighbor,
                    curr_time + adj_graph[curr_vertex][neighbor]["distance"] + 1,
                    path
                    + [
                        (
                            neighbor,
                            curr_time
                            + adj_graph[curr_vertex][neighbor]["distance"]
                            + 1,
                        )
                    ],
                    visited,
                    adj_graph,
                    num_vertices,
                    max_time,
                    flow_rate,
                    is_elephant,
                ),
            )
    if curr_vertex != "AA":
        visited.remove(curr_vertex)
    return max_total_pressure


def solve1(lines):
    flow_rate, adj_graph, start_valve = parse(lines)
    path = []
    vertices = ["AA"] + list(
        [vertex for vertex in flow_rate.keys() if flow_rate[vertex]]
    )

    paths = {}
    for fr in vertices:
        paths[fr] = shortest_path(adj_graph, fr, vertices)

    visited = set()
    max_time = 30
    return dfs(start_valve, 0, [], visited, paths, len(vertices), max_time, flow_rate)


def solve2(lines):
    flow_rate, adj_graph, start_valve = parse(lines)
    path = []
    vertices = ["AA"] + list(
        [vertex for vertex in flow_rate.keys() if flow_rate[vertex]]
    )

    paths = {}
    for fr in vertices:
        paths[fr] = shortest_path(adj_graph, fr, vertices)

    visited = set()
    max_time = 26
    return dfs2(
        start_valve, 0, [], visited, paths, len(vertices), max_time, flow_rate, False
    )


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
