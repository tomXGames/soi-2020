opening = ['(', '[', '{']
closing = [')', ']', '}']

def balanced(text):
    open = []
    for i, char in enumerate(text):
        if i == 0:
            if char in closing:
                return False
            else:
                open.append(char)
        else:
            if char in opening:
                open.append(char)
            elif char in closing:
                if opening[closing.index(char)] in open and opening[closing.index(char)] == open [-1]:
                    open.pop()
                else:
                    return False
    if open.__len__()>0:
        return False
    return True

output = balanced(input())
if output:
    print('balanced')
else:
    print('imbalanced')