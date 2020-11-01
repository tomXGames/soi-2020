f = open('test5.txt', 'r').readlines()
t = int(f[0])
cases = []
for i in range(t):
    case = []
    l = int(f[i*2+1].strip('\n'))
    case.append(l)
    m = [int(x) for x in f[i*2+2].split(' ')]
    case.append(m)
    cases.append(case)
solution = []
for case in cases:
    m = case[1]
    previous = m[0] 
    count = 1 
    op = list()
    for index, i in enumerate(m):
        if not index == len(m)-1: nex =index+1  
        else: nex = index
        if previous > i: 
            op.append(i)
        elif i>previous and i> m[nex]: 
            for j in list(x for x in op if previous <= x < i):
                op.remove(j)
                count += 1 
            op.append(i)
        elif i > previous:
            for j in list(x for x in op if previous <= x < i):
                op.remove(j)
                count += 1
        elif index == len(m) -1:
            if max(m) > i > previous :
                op.append(i)
            for j in op:
                count += 1
        
        previous = i
    solution.append(count)
outf = open('out5.txt', 'w')
print(solution)
for i, sol in enumerate(solution):
    outf.write(f'Case #{i}: {sol} \n')