def primality(num):
    if num == 1:
        return False
    for i in range(2, num-1):
        if num % i == 0:
            return False
    return True

out = primality(int(input()))
if out:
    print('prime')
else:
    print('composite')