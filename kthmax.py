line1 = [int(x) for x in input().split(' ')]
line2 = [int(x) for x in input().split(' ')]
line2.sort(reverse=True)
print(line2[line1[1]])