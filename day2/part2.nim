import strutils

### Not proud of this, but its friday late night

proc hasPlayerWin(play: string): int =
    let s: seq[string] = play.split(" ")

    if s[0] == "A":
        if s[1] == "X":
            return 3 + 0
        elif s[1] == "Y":
            return 1 + 3
        elif s[1] == "Z":
            return 2 + 6
    elif s[0] == "B":
        if s[1] == "X":
            return 1 + 0
        elif s[1] == "Y":
            return 2 + 3
        elif s[1] == "Z":
            return 3 + 6
    elif s[0] == "C":
        if s[1] == "X":
            return 2 + 0
        elif s[1] == "Y":
            return 3 + 3
        elif s[1] == "Z":
            return 1 + 6


let textLines = readFile("input.txt").splitLines()

var totalScore = 0

for txtLine in textLines:
    if (txtLine == ""):
        continue

    totalScore += hasPlayerWin(txtLine)
    echo totalScore

