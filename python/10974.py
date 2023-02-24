from itertools import permutations

N = int(input())

numList = [i for i in range(1, N+1)]

for i in permutations(numList, len(numList)):
    for tupIdx in range(N):
        print(i[tupIdx], end=' ')
    print()
    
