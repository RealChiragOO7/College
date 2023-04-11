def DFS(start_node, graph):
    visited = set()
    stack = [start_node]

    while stack:
        node = stack.pop()

        if node not in visited:
            visited.add(node)
            print(node, end=" ")

            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)


graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1],
    4: [1, 2]
}

DFS(0, graph)