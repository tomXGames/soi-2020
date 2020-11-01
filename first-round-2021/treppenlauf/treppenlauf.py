f = open('test4.txt', 'r').readlines()
t = int(f[0])
cases = {}
for i in range(t):
    cases[i] = []
    n = [int(f[i*3+1])]
    cases[i].append(n)
    cases[i].append([int(x) for x in f[(i*3)+2].split(' ')])
    cases[i].append([int(x) for x in f[(i*3)+3].split(' ')])

solutions = {}
for i, items in cases.items():
    currentmax = int()
    right = items[1]
    left = items[2]
    for k, nums in enumerate(right):
        left = [x for x in left if x > currentmax/2-1]
        for l, num in enumerate(left):
            sum1 = num + nums+ abs(k-l)
            if currentmax < sum1: currentmax = sum1
    solutions[i] = currentmax
    print(i)

outf = open('out3.txt', 'w')
for i, val in solutions.items():
    outf.write(f'Case #{i}: {val}\n')