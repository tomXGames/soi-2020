input = input().split(' ')

if input[0] == '0':
    print(float(input[1]) + float(input[2]), end='')
elif input[0] == '1':
    print(float(input[1]) - float(input[2]), end='')
elif input[0] == '2':
    print(float(input[1]) * float(input[2]), end='')