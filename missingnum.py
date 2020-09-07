def missingnum(array):
    found = False
    num = 1
    while not found:
        if not num in array:
            found = True
        else:
            num += 1

    return num

input()
array = [int(x) for x in input().split(' ')]
print(str(missingnum(array)))