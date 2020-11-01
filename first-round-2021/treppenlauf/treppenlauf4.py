f = open('test7.txt', 'r').readlines()
t = int(f[0])
cases = {}
for i in range(t):
    cases[i] = []
    n = [int(f[i*3+1])]
    cases[i].append(n)
    cases[i].append([int(x) for i, x in enumerate(f[(i*3)+2].split(' '))])
    cases[i].append([int(x) for i, x in enumerate(f[(i*3)+3].split(' '))])

solutions = []
for i, items in cases.items():
    l1 = [int(x)+i for i, x in enumerate(items[1])]
    max1 = max(l1)
    # out1 = 0
    # indx1 = None
    # for i in [i for i, j in enumerate(l1) if j == max1]:
    #     if items[1][i] > out1:
    #         out1 = items[1][i]
    #         indx1 = i
    l2 = [abs(int(x)-i) for i, x in enumerate(items[2])]
    max2 = max(l2)
    # out2 = 0
    # indx2 = None
    # for i in [i for i, j in enumerate(l2) if j == max2]:
    #     if items[2][i] > out2:
    #         out2 = items[2][i]
    #         indx2 = i
    # solutions.append(out1 + out2 + abs(indx1-indx2))  
    solutions.append(max1+max2)
outf = open('out7.txt', 'w')
for i, val in enumerate(solutions):
    outf.write(f'Case #{i}: {val}\n')