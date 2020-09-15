#region variables
in1 = input().split(' ')
n = int(in1[0])
m = int(in1[1])
out = [list() for i in range(n)]
stoflococcus = True
checked = []
#endregion
checked = []
stoflococcus = True
def check(n):
    global stoflococcus
    for i in n:
        if len(i) >2 or len(i) <1:
            stoflococcus = False
        
        
#region input
for i in range(m):
    in2 = [ int(x) for x in input().split(' ')]
    out[in2[0]].append(in2[1])
    out[in2[1]].append(in2[0])

#endregion
check(out)
if stoflococcus:
    print('stoflococcus', end='')
else:
    print('other', end='')