def speedstats(speeds):             
    speeds = [int(speed) for speed in speeds]
    print(speeds)
    speeds.sort(key=abs ,reverse=True)
    min(speeds, key=abs)
    print(speeds)
    return speeds

input()
speeds = input().split(' ')
print(speeds)
copy = speedstats(speeds)
print(copy)
string=''
for speed in copy:
    string += f'{speed}\n'
print(string, end='')