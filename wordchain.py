def wordchain(word1, word2):
    if word1.__len__() > word2.__len__():
        longer = word1
        shorter = word2
    else:
        longer = word2
        shorter = word1
    for i, char in enumerate(shorter):
        if i == 0:
            newarr = longer
        if char in newarr:
            newarr = newarr[newarr.index(char)+1:]
            continue
        else:
            return False
    return True

word1 = input()
word2 = input()
out = wordchain(word1, word2)
if out:
    print('yes')
else:
    print('no')