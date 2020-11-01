import string
f = open('test2.txt', 'r').readlines()
t = int(f[0])
cases = {}
solutions = [[None for x in range(26)] for i in range(t)]
for i in range(t):
    cases[i] = f[i+1].split(' ')

for i, item in cases.items():
    for j, c in enumerate(list(item[0])):
        if not solutions[i][string.ascii_lowercase.index(c)] == list(item[1])[j] and not solutions[i][string.ascii_lowercase.index(c)] == None:
            solutions[i] = False
            break
        else:
            solutions[i][string.ascii_lowercase.index(c)] = list(item[1])[j]
outf = open('out2.txt', 'w')
for i, val in enumerate(solutions):
    out = ''
    if type(val) == bool:
        outf.write(f'Case #{i}: No\n')
    else:
        for j, c in enumerate(val):
            if not c == None: 
                out += c
            elif c == None:
                out += 'a'
        if not out == '':
            outf.write(f'Case #{i}: Yes\n')
            outf.write(out+'\n')


