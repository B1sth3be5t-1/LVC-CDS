import math

n, m, s, p, q = [int(x) for x in input().split(" ")]

numPages = math.ceil(n/m)

current = [set() for i in range(numPages)]
result = [set() for i in range(numPages)]

for i in range(p):
    el = int(input())
    current[math.floor((el - 1)/m)].add(el)

for i in range(q):
    el = int(input())
    result[math.floor((el - 1)/m)].add(el)


differences = [current[i].intersection(result[i]) for i in range(len(result))]

num_operations = [[abs(len(differences[i]) - len(current[i])),abs(len(differences[i]) - len(result[i]))] for i in range(len(result))]

operations = []

for i in range(len(current)):
    counts = 0
    if num_operations[i][0] == 0 and num_operations[i][1] == 0:
        counts = 0
    elif num_operations[i][1] == 0:
        if num_operations[i][0] > m/2:
            counts = 1 + len(result[i])
        else:
            counts = num_operations[i][0]
    elif num_operations[i][0] == 0:
        if num_operations[i][1] > m / 2:
            if i == numPages - 1:
                counts = 1 + n % m - len(result[i])
            else:
                counts = 1 + m - len(result[i])
        else:
            counts = num_operations[i][1]
    else:
        first_op = num_operations[i][0] + num_operations[i][1]
        second_op = 1 + len(result[i])
        if i == numPages - 1:
            third_op = 1 + n % m - len(result[i])
        else:
            third_op = 1 + m - len(result[i])
        counts = min(first_op, second_op, third_op)

    operations.append(counts)


lmnop = 0
rightMost = 0

for i in range(numPages):
    if operations[i] != 0:
        lmnop = i
        break

for i in range(numPages):
    if operations[numPages - i - 1] != 0:
        rightMost = numPages - i - 1
        break

totCount = sum(operations)

s -= 1

if abs(s - lmnop) < abs(s - rightMost):
    totCount += (s - lmnop) + (rightMost - lmnop)
else:
    totCount += (rightMost - s) + (rightMost - lmnop)


print(totCount)