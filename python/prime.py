# n 이 소수인지 아닌지를 구할 때 

# 1. "n - 1" 까지 "모든 수"를 돌면서 나눠지는지 확인
def prime1(n: int):
    if(n < 2):
        return False # 1 의 처리를 위한 부분
    for i in range(2:n):
        if n % i == 0: # 2부터 차례로 돌면서 나눠지는 수가 있으면 소스가 아님
            return False
    return True # 위에서 모든 경우를 찾아봤을 때 나눠지는 수가 없는 경우

# 2. "n/2" 까지 돌면서 "모든 수"를 돌면서 나눠지는지 확인
def prime2(n: int):
    if(n < 2):
        return False
    for i in range(2, n / 2 + 1):
        if(n % i == 0):
            return False
    return True

# 3. "sqrt(n)" 까지 돌면서 "모든 수"를 돌면서 나눠지는지 확인
def prime3(n: int):
    if(n < 2):
        return False:
    for i in range(2, n) 
