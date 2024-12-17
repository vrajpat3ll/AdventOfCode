# https://adventofcode.com/2023/day/3


contents = open("C:/CODING/CODE/Advent Of Code/Dec-2023/input.txt")
data = contents.readlines()
# print(data)

directions = {
    (1, 0), (1, 1), (1, -1),
    (0, 1), (0, -1),
    (-1, 0), (-1, 1), (-1, -1)
}


def isDot(char):
    return (char == '.')


def isNumber(string: str):
    return string.isdecimal()


def parseInt(string: str):
    #....64.............998...........875...$.54545........5353
    if not isNumber(string[0]):
        raise ValueError('Not a number!')
    num_str = ''
    for char in string:
        if isNumber(char):
            num_str += char
        else:
            break
    return int(num_str)

def getNextPosition(pos: tuple, direction: tuple):
    newX = pos[0] + direction[0]
    newY = pos[1] + direction[1]
    return (newX, newY)



print('\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n')
for line in data:
    print(line)

sum = 0
line = data[0]







contents.close()
