def runlengthencodingnosize(array):
    output = []
    for i, val in enumerate(array):
        if i == 0:
            output.append({val: 1})
        elif val == array[i-1]:
            output[-1].update((k, v+1) for k, v in output[-1].items())
        else:
            output.append({val: 1})
        
    return output

nums = int(input())
array = [int(x) for x in input().split(' ')]
out = runlengthencodingnosize(array)
for i in out:
    print(f'{next(iter(i))} {i[next(iter(i))]}')