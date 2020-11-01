import string
import random
f = open('test7.txt', 'r').readlines()
t = int(f[0])
cases = {}
solutions = [None for i in range(t)]
for i in range(t):
    cases[i] = [[int(x) for x in f[i*3+1].split(' ')]]
    solutions[i] = [[None for i in range(26)] for x in range(2)]
    for j in range(cases[i][0][0]):
        cases[i].append([x.strip('\n') for x in f[i*3+j+2].split(' ')])

for i, case in cases.items():
    n = case[0][0]
    l = case[0][1]
    word1 = list(case[1][0])
    word2 = list(case[2][0])
    for k, c in enumerate(word1):
        indices1 = [index for index, element in enumerate(word1) if element == word2[k]]
        indices2 = [index for index, element in enumerate(word2) if element == c]
        letter = random.choice(string.ascii_lowercase)
        solutions[i][0][string.ascii_lowercase.index(c)] = letter
        for l in indices1:
            if solutions[i][1][string.ascii_lowercase.index(word2[l])]  == None:
                solutions[i][1][string.ascii_lowercase.index(word2[l])] = letter
            if solutions[i][0][string.ascii_lowercase.index(word2[l])] == None:
                solutions[i][0][string.ascii_lowercase.index(word1[l])] = letter
        for l in indices2:
            if solutions[i][1][string.ascii_lowercase.index(word2[l])]  == None:
                solutions[i][1][string.ascii_lowercase.index(word2[l])] = letter
            if solutions[i][0][string.ascii_lowercase.index(word2[l])] == None:
                solutions[i][0][string.ascii_lowercase.index(word1[l])] = letter


outf = open('out7.txt', 'w')
for i, val in enumerate(solutions):
    word = ''
    print(cases[i][1][0])
    print(solutions[i])
    for c in cases[i][1][0]:
        if c == None:
            word += 'a'
        else: word += solutions[i][0][string.ascii_lowercase.index(c)]
    outf.write(f'Case #{i}: {len(list(set(list(word))))} {word} \n')
    print(val)
    for cs in val:
        print('ok')
        for css in cs:
            if css == None:
                outf.write('a')
            else:
                outf.write(css)
        outf.write('\n')
