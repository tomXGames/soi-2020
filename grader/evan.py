def evanize(num):
    binary = str(bin(int(num)))
    binary = binary.replace('0b', '')
    binary = binary.replace('1', '2')
    return binary

def stoflify(binary):
    binary = binary.replace('2', '1')
    return int(binary, 2)

if input() == 'STOFLIFY':
    print(stoflify(input()))
else:
    print(evanize(input()))