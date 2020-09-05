def solution(arraylen, array):
    solution = 0
    for i, num in enumerate(array):
        for num2 in array[i:]:
            if (array.__contains__(num+num2)):
                solution += array.count(num+num2)
    return solution
    
arraylen = input() 
array = input().split(' ')
array = [int(i) for i in array]
print(solution(arraylen, array))