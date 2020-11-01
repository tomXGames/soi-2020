f = open('test3.txt', 'r').readlines()
t = int(f[0])
cases = []
for i in range(t):
    case = []
    l = int(f[i*2+1].strip('\n'))
    case.append(l)
    m = [int(x) for x in f[i*2+2].split(' ')]
    case.append(m)
    cases.append(case)
print(cases)
solution = []
for case in cases:
    m = case[1]
    currentcut = []   
    for index, i in enumerate(m):
        if index == 0:
            previous = i
            currentcut.append(i)
        elif not i == previous:
            if max(m) == i and i in currentcut:
                previous = i
            else: 
                currentcut.append(i)
                previous = i
    solution.append(len(currentcut))
print(solution)
outf = open('out3.txt', 'w')
for i, sol in enumerate(solution):
    outf.write(f'Case #{i}: {sol} \n')