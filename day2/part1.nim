import strutils

proc getPoints(play: string): int = 
    case play:
    of "X":
       return 1
    of "Y":
       return 2
    of "Z":
       return 3

proc isDraw(play: string): bool = 
    if play == "A X" or play == "B Y" or play == "C Z":
        return true

    return false

proc isWin(play: string): bool = 
    if play == "B X" or play == "C Y" or play == "A Z":
        return true

    return false

proc hasPlayerWin(play: string): int =
    let s: seq[string] = play.split(" ")
    let playerPoints: int = getPoints(s[1])

    if isDraw(play):
        return playerPoints + 3
    elif isWin(play):
        return playerPoints + 0
    else:
        return playerPoints + 6

let textLines = readFile("input.txt").splitLines()

var totalScore = 0

for txtLine in textLines:
    if (txtLine == ""):
        continue

    totalScore += hasPlayerWin(txtLine)
    echo totalScore

echo hasPlayerWin("A Y")
echo hasPlayerWin("B X")
echo hasPlayerWin("C Z")
