in1 = input().split(' ')
n = int(in1[0])
m = int(in1[1])
out = [list() for i in range(n)]
for i in range(m):
    in2 = [ int(x) for x in input().split(' ')]
    out[in2[0]].append(in2[1])
    out[in2[1]].append(in2[0])
stars = None
star = None
center = None
for i, array in enumerate(out):
    if len(array) == n-1:
        if star == None:
            star = True
        else:
            star = False
            break
        
    elif len(array) == 1:
        if not center == None:
            if center == array[0]:
                continue
            else:
                star = False
                break
        if center == None:
            center = array[0]
if n <3:
    star = True

if star:
    print('star', end='')
else:
    print('other', end='')