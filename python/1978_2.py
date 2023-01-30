# 에라토스테네스의 체 사용
prime = []
check = [False for i in range(1001)]

n = 1000
check[1] = True
for i in range(2, 1001):
    # check 배열의 true 는 지워졌을 때, false 는 지워지지 않았을 떄를 의미한다.
    # 즉 check[i] == True 는 합성수, check[i] == False 는 소수이다.
    if(check[i] == False):
        prime.append(i)
        for j in range(i * i, n + 1, i):
            check[j] = True 


N = int(input())
numList = list(map(int, input().split(' ')))
primeCnt = 0
for i in range(len(numList)):
    if(check[numList[i]] == False):
        primeCnt = primeCnt + 1

print(primeCnt)