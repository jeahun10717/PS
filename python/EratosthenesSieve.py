prime = []
check = [False for i in range(101)]

n = 100
for i in range(2, 101):
    # check 배열의 true 는 지워졌을 때, false 는 지워지지 않았을 떄를 의미한다.
    # 즉 check[i] == True 는 합성수, check[i] == False 는 소수이다.
    if(check[i] == False):
        prime.append(i)
        for j in range(i * i, n + 1, i):
            check[j] = True 

print(prime)