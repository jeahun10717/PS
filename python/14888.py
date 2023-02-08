from itertools import permutations
import math

N = int(input())

numList = list(map(int, input().split()))
plus, minus, multi, divide = map(int, input().split())

opList = []

for i in range(plus):
    opList.append(0)
for i in range(minus):
    opList.append(1)    
for i in range(multi):
    opList.append(2)
for i in range(divide):
    opList.append(3)

minPermu = int(1e9)
maxPermu = int(-1e9)
for permuIdx in permutations(opList, len(opList)):
    opNum = numList[0]
    for i in range(len(opList)):
        if(permuIdx[i] == 0):
            opNum += numList[i+1]
        elif(permuIdx[i] == 1):
            opNum -= numList[i+1]
        elif(permuIdx[i] == 2):
            opNum *= numList[i+1]
        elif(permuIdx[i] == 3):    
            opNum = int(opNum / numList[i+1])
    minPermu = min(minPermu, opNum)
    maxPermu = max(maxPermu, opNum)

print(maxPermu)
print(minPermu)