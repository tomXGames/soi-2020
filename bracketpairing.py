def bracketpairs(text, l ,r):
    text = text[l-1:r]
    open = []
    count = 0
    for i, char in enumerate(text):
        if i == 0 and char == '(':
            open.append(char)
        else:
            if char == '(':
                open.append(char)
            elif char == ')' and '('in open:
                    open.pop(-1)
                    count += 2
    return count

text = input()
n = int(input())
for i in range(n):
    #region getting Input
    lr = [int(x) for x in input().split(' ')]
    l = lr[0]
    r = lr[1]
    #endregion
    print(bracketpairs(text, l, r))