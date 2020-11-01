in1 = input().split(' ')
n = int(in1[0])
m = int(in1[1])
out = [list() for i in range(n)]
for i in range(m):
    in2 = [ int(x) for x in input().split(' ')]
    out[in2[0]].append(in2[1])
    out[in2[1]].append(in2[0])
    
wrenchflies = 0
for i, array in enumerate(out):
    if len(array) == 2:
        if len(out[array[0]]) == 1 and len(out[array[1]]) == 1:
            wrenchflies += 1
    else:
        continue
print(wrenchflies)
