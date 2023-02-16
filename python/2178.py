from collections import deque

# 입력
N, M = map(int, input().split())
graph = []
dist = [[987654321 for _ in range(M)] for _ in range(N)]
for _ in range(N):
    graph.append(input())

dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def bfs(sty, stx): # 시작점의 x, y 좌표가 주어진다
    result = 0
    q = deque()
    q.append((sty, stx))
    dist[sty][stx] = 1
    while q:
        cury, curx = q.popleft()
        for i in range(len(dir)):
            nexty = cury + dir[i][0]
            nextx = curx + dir[i][1]        
            if nexty <= N - 1 and nexty >= 0 and nextx <= M - 1 and nextx >= 0 : # 다음으로 방문하는 곳이 입력배열의 범위를 넘어서지 않을 떄
                if int(graph[nexty][nextx]) == 1: # 0은 갈수 없는 곳, 1은 갈수 있는곳 체크
                    if dist[cury][curx] + 1 < dist[nexty][nextx]: # 현재의 노드 + 1 이 다음으로 갈 노드의 값보다 더 작을 때
                        dist[nexty][nextx] = dist[cury][curx] + 1
                        q.append((nexty, nextx))

bfs(0, 0)
print(dist[N - 1][M - 1])