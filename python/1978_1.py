# n 이 주어졌을 때 그 수가 소수인지 구하는 방법 사용
def prime(n: int):
    if n < 2:
        return False
    for i in range(2, n):
        if i * i <= n:
            if n % i == 0:
                return False
        else: break
    return True

N = int(input())
numList = list(map(int, input().split(' ')))

primeCnt = 0
for i in range(len(numList)):
    if(prime(numList[i])):
        primeCnt = primeCnt + 1

print(primeCnt)