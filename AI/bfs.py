def bfs(start, num):
    global graph
    answer = []
    queue = []
    queue.append(start)
    answer.append(start)
    visited = {}
    count = 0
    while (len(answer) < num):

        p = queue[0]
        del queue[0]
        if (p not in visited):

            for i in range(len(graph[p])):
                if graph[p][i] not in answer:
                    queue.append(graph[p][i])
                    answer.append(graph[p][i])
        visited[p] = 1

    return answer
if __name__ == '__main__':
    num = 7
    graph = [[] for i in range(7)]

    graph[0].append(1)
    graph[0].append(3)
    graph[3].append(1)
    graph[3].append(6)
    graph[3].append(4)
    graph[1].append(6)
    graph[4].append(2)
    graph[4].append(5)
    graph[2].append(1)
    graph[5].append(2)
    graph[5].append(6)
    graph[6].append(4)

    answer = bfs(0, num)

    print("BFS = ", answer)