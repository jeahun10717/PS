def GCD(a : int, b : int):
    if(b == 0):
        return a
    else:
        return GCD(b, a%b)

def LCM(a : int, b : int, gcd : int):
    return int(a * b / gcd)

T = int(input())

for i in range(0, T):
    a, b = map(int, input().split(' '))
    print(LCM(a, b, GCD(a, b)))
