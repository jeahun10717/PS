import sys

M = int(input())
s1 = set()
allset = set(i for i in range(1,21))

for i in range(M):
    inpStr = sys.stdin.readline().split()
    if(inpStr[0] == 'add'):
        s1.add(int(inpStr[1]))
    elif(inpStr[0] == 'remove'):
        s1.discard(int(inpStr[1]))
    elif(inpStr[0] == 'check'):
        if int(inpStr[1]) in s1: print(1)
        else: print(0)
    elif(inpStr[0] == 'toggle'):
        if int(inpStr[1]) in s1: # 값이 존재하면
            s1.discard(int(inpStr[1]))
        else: # 값이 존재하지 않으면
            s1.add(int(inpStr[1]))
    elif(inpStr[0] == 'all'):
        s1 = s1.union(allset)
    elif(inpStr[0] == 'empty'):
        s1.clear()

