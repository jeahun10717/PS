def GCD(a:int, b:int):
    if b == 0:
        return a
    else:
        return GCD(b, a%b)

t = int(input())

for _ in range(t):
    print("*************************************8")
    arr = list(map(int, input().split(' ')))
    n, numList = arr[0], arr[1:]
    print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2")
    res = 0
    for i in range(n - 1):
        for j in range(i+1, n):
           res = res + GCD(numList[i], numList[j])
        #    print(i, j, res)
    print(res)
