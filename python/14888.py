from itertools import permutations
import math

N = int(input())

numList = list(map(int, input().split()))
plus, minus, multi, divide = map(int, input().split())

opList = []

opList.extend([0 for i in range(plus)])
opList.extend([1 for i in range(minus)])
opList.extend([2 for i in range(multi)])
opList.extend([3 for i in range(divide)])

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