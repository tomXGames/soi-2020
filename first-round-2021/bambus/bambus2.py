f = open('test4.txt', 'r').readlines()
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
    out = 0
    cut = list()
    current = list()
    previous = m[0] 
    count = 0 
    for index, i in enumerate(m):
        if i == 1 and previous == 2:
            cut.append(i)
        elif index == 0 and i ==1:
            cut.append(i)
        previous = i
    solution.append(int(len(cut)+1))
print(solution)
outf = open('out4.txt', 'w')
for i, sol in enumerate(solution):
    outf.write(f'Case #{i}: {sol} \n')