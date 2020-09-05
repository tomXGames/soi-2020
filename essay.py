def essay(nums, maxwords):
    max = 0
    for i in nums:
        for j in nums[:i]:
            if i + j > max and i + j <= maxwords:
                max = i+j
    return max

line1 = input().split(' ')
numsentences = int(line1[0])
maxwords = int(line1[1])
nums = []
for i in range(numsentences):
    nums.append(int(input().split(' ')[0]))
print(str(essay(nums, maxwords)))