total = 0

def contains(range, rangeMax):
    if int(range[0]) >= int(rangeMax[0]) and int(range[1]) <= int(rangeMax[1]):
        return True

    return False

def containsPartTwo(range, rangeMax):
    if (int(range[1]) >= int(rangeMax[0]) and int(rangeMax[0]) >= int(range[0])):
        return True

    return False

def parse(x):
    global total
    rangeOne = x[0].split("-")
    rangeTwo = x[1].split("-")
    fullyOverlap = contains(rangeOne, rangeTwo) or contains(rangeTwo, rangeOne)
    overlap = containsPartTwo(rangeOne, rangeTwo) or containsPartTwo(rangeTwo, rangeOne)
    if (overlap or fullyOverlap):
        total = total + 1
    else:
        print(rangeOne, rangeTwo)

with open("input.txt", "r") as file:
    lines = file.readlines()
    l = list(map(lambda x: x.split(","), lines))
    [parse(x) for x in l]
    print(total)

