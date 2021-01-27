parentList = []
numSeg, numPoint = map(int, input().split())
for point in range(numSeg):
    u, v = map(int, input().split())
    parentList.append((u, 'l'))
    parentList.append((v, 'r'))

points = list(map(int, input().split()))
for point in points:
    parentList.append((point, 'p'))

parentList.sort()
# print(parentList)
segments = 0
pointsDict = {}
for pair in parentList:
    if(pair[1] == 'l'):
        segments += 1
    elif pair[1] == 'r':
        segments -= 1
    else:
        pointsDict[pair[0]] = segments

result = ''
for i in points:
    result += str(pointsDict[i]) + ' '
print(result[:-1])
