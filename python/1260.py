from collections import deque

def DFS(start: int):
    check[start] = 1
    print(start, end = " ")
    for i in range(len(graph[start])):
        next = graph[start][i]
        if(check[next] == 0):
            DFS(next)

def BFS(start: int):
    check[start] = 1
    # print(start, end = " ")
    q = deque()
    q.append(start)
    while q:
        curNode = q.popleft()
        print(curNode, end = " ")
        for i in range(len(graph[curNode])):
            nextNode = graph[curNode][i]
            if check[nextNode] == 0:
                # print(nextNode, " ")
                check[nextNode] = 1
                q.append(nextNode)

                



N, M, V = map(int, input().split()) # 정점의 개수, 간선의 개수, 시작노드

check = [0 for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    st, end = map(int, input().split())
    graph[st].append(end)
    graph[end].append(st)
    graph[st].sort()
    graph[end].sort()

DFS(V)
print()
check = [0 for _ in range(N + 1)] # 초기화
BFS(V)
print()