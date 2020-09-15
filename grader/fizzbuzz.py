num= int(input())
for i in range(num):
    output = ""
    if (i+1)%3 == 0 or (i+1)%5 == 0:
        if (i+1)%3 == 0:
            output+= 'Fizz'
        if (i+1)%5 == 0:
            output+='Buzz'
    else:
        output = str(i+1)
    print(output)