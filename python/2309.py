numList = []
exceptList = []
sum = 0
for _ in range(9):
    inp = int(input())
    numList.append(inp)
    sum += inp
breakFlag = False
for i in range(8):
    if(breakFlag == True): break
    for j in range(i + 1, 9):
        if(sum - (numList[i] + numList[j])) == 100:
            if(breakFlag == True): break
            exceptList.extend([numList[i], numList[j]])
            breakFlag = True
    
numList.sort()
for i in range(9):
    if(numList[i] == exceptList[0] or numList[i] == exceptList[1]):
        continue
    else:
        print(numList[i])

            
            

    