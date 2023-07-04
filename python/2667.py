from collections import deque
import sys

dirX = [0, 0, 1, -1]
dirY = [1, -1, 0, 0]

T = int(input())
graph = []
for i in range(T):
    graph.append(list(map(int, input())))

def BFS(sty:int, stx:int):
    q = deque()
    q.append((sty, stx))
    graph[sty][stx] = 0
    danCnt = 1
    while(q):
        curY, curX = q.popleft()
        for i in range(4):
            nxY = curY + dirY[i]
            nxX = curX + dirX[i]
            if(nxY >= 0 and nxY < T and nxX >= 0 and nxX < T): # map 의 범위를 벗어나지 않고
                if(graph[nxY][nxX] == 1): # map 을 방문할 수 있는 곳일 때
                    q.append((nxY, nxX))
                    graph[nxY][nxX] = 0
                    danCnt += 1
                    
    return danCnt

totCntList = []
for i in range(T):
    for j in range(T):
        if(graph[i][j] == 1):
            totCntList.append(BFS(i, j))

totCntList.sort()
print(len(totCntList))
for i in range(len(totCntList)):
    print(totCntList[i])
                
