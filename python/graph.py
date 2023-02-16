# 인접리스트의 구현
node, edge = map(int, input().split())

graph = [[] for i in range(node)]

for _ in range(edge):
    startNode, endNode = map(int, input().split())
    graph[startNode].append(endNode)
    graph[endNode].append(startNode)

# 인접행렬의 구현
node, edge = map(int, input().split())

graph = [[] for j in range(node) for i in range(node)]

for _ in range(edge):
    startNode, endNode = map(int, input().split())
    graph[startNode][endNode] = 1
    graph[endNode][startNode] = 1

# 인접행렬에서 n행 m열의 정보가 주어지는 경우
row, column, edge = map(int, input().split())

graph = [[] for j in range(column) for i in range(row)]

for _ in range(edge):
    startNode, endNode = map(int, input().split())
    graph[startNode][endNode] = 1
    graph[endNode][startNode] = 1