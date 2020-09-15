nums = [int(x) for x in input().split(' ')]
if nums[0]-2 == nums[1] or nums[0] == nums[1]:
    if nums[0] % 2 == 0 or nums[0] % 2 == 0:
        print(sum(nums))
    else:
        print(sum(nums) + 1)
else:
    print('Never')