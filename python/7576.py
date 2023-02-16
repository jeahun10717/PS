from collections import deque

M, N = map(int, input().split())

# box = [[0 for column in range(N)] for row in range(M)]

box = []
dir = [[0, 1],[1, 0],[0, -1],[-1, 0]]
ripedTmtCnt = 0 # 익은 토마토 개수
tmtChk = M * N # 박스안의 전체 토마토 개수

for _ in range(N):
    box.append(list(map(int, input().split())))

# 처음 queue 에 삽입할 부분 
q = deque()
for y in range(N):
    for x in range(M):
        if box[y][x] == 1:
            ripedTmtCnt += 1
            q.append((y, x, 0))
        elif box[y][x] == -1:
            tmtChk -= 1

def bfs():
    global q, ripedTmtCnt, tmtChk
    result = 0
    while q:
        curY, curX, curDay = q.popleft()
        for i in range(len(dir)):
            nextY = curY + dir[i][0]
            nextX = curX + dir[i][1]
            nextDay = curDay + 1
            if nextY >= 0 and nextY <= N - 1 and nextX >= 0 and nextX <= M - 1: # 다음방문노드가 박스범위를 벗어나지 않고
                if box[nextY][nextX] == 0: # 다음방문노드가 익지 않은 토마토이고
                    box[nextY][nextX] = 1
                    ripedTmtCnt += 1 # 익은 토마토 개수 +1
                    q.append((nextY, nextX, nextDay))
                    result = nextDay
    
    return result

if ripedTmtCnt == tmtChk: print(0) # 이미 모든 토마토가 익은 상태일 때       
else:
    day = bfs()
    if ripedTmtCnt != tmtChk: print(-1)
    else: print(day)
