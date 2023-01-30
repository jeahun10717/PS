def GCD(a : int, b : int):
    if(b == 0):
        return a
    else:
        return GCD(b, a % b)

def LCM(a : int, b : int, gcd : int):
    return int(a * b / gcd) # 주의! 여기서 int 로 타입캐스팅 안해주면 72.0 처럼 나와서 오답으로 처리됨


a, b = map(int, input().split(' '))

gcd = GCD(a, b)
print(gcd)
print(LCM(a, b, gcd))