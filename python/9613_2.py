import math

t = int(input())

for _ in range(t):
    arr = list(map(int, input().split(' ')))
    n, numList = arr[0], arr[1:]
    res = 0
    for i in range(n - 1):
        for j in range(i+1, n):
           res = res + math.gcd(numList[i], numList[j])
        #    print(i, j, res)
    print(res)
