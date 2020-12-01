import string
import sys

# this code fucking sucks and fuck python i hate it, why am i still using it fuck my life
sys.setrecursionlimit(100000)
def secretcode(char, wordcount, letter, case, casenumber):
    if casenumber == 0: print(case)
    if solutions[casenumber][wordcount][string.ascii_lowercase.index(char)] == None:
        indices = [index for index, element in enumerate(case[1][wordcount]) if element == char]
        solutions[casenumber][wordcount][string.ascii_lowercase.index(char)] = letter
        for i, word in enumerate(case[1]):
            if not i == wordcount :
                for c in indices:
                    secretcode(word[c], i, letter, case, casenumber)

f = open('test15.txt', 'r').readlines()
t = int(f[0])
del f[0]
currentline=0
cases = {}
solutions = [None for i in range(t)]
for i in range(t):
    cases[i] = [[int(x) for x in f[0].split(' ')]]
    del f[0]
    solutions[i] = [[None for i in range(26)] for x in range(cases[i][0][0])]
    cases[i].append([])
    for j in range(cases[i][0][0]):
        cases[i][1].append([x.strip('\n') for x in f[0].split(' ')][0])
        del f[0]
print(cases[0])

for i, case in cases.items():
    word1 = case[1][0]
    for k, c in enumerate(word1):
        letter = string.ascii_lowercase[(string.ascii_lowercase.index(c)+1)%26]
        secretcode(c, 0, letter, case, i)

outf = open('out15.txt', 'w')
for i, val in enumerate(solutions):
    word = ''
    for c in cases[i][1][0]:
        if c == None:
            word += 'a'
        else: word += solutions[i][0][string.ascii_lowercase.index(c)]
    outf.write(f'Case #{i}: {len(list(set(list(word))))} {word} \n')
    for cs in val:
        for css in cs:
            if css == None:
                outf.write('a')
            else:
                outf.write(css)
        outf.write('\n')