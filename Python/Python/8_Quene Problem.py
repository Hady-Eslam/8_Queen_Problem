from random import *

Path = []
chess = [[0 for i in range(0, 8, 1)] for j in range(0, 8, 1)]


############################################################################


def issafe(row, col):

    for i in range(0, 8, 1):
        if chess[i][col] == 1:
            return False

    i = row-1
    j = col-1
    while i > -1 and j > -1:
        if chess[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i = row - 1
    j = col + 1
    while i > -1 and j < 8:
        if chess[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True


############################################################################


def solve(row):
    if row == 7:
        for j in range(0, 8, 1):
            if issafe(row, j):
                Path.append([row, j])
                return True
        return False

    for j in range(0, 8, 1):
        if issafe(row, j):
            chess[row][j] = 1
            Path.append([row, j])

            if solve(row+1):
                return True

            Path.pop(-1)
            chess[row][j] = 0
    return False


############################################################################


def printpath(chess):

    with open("8_Quene", 'w') as f:
        f.write("The Solution :\n\n----------------------------------------- \n\n")
        string = ""

        for i in range(0, 8, 1):
            for j in range(0, 8, 1):
                chess[i][j] = 0
                string += "0  "
            string += '\n'
        f.write(string+"\n----------------------------------------- \n\n")

        for i in range(0, 8, 1):
            chess[Path[i][0]][Path[i][1]] = 1
            string = "The Next Step ::: ==>>\n\n"
            for i in range(0, 8, 1):
                for j in range(0, 8, 1):
                    string += str(chess[i][j]) + "  "
                string += '\n'
            f.write(string+"\n----------------------------------------- \n\n")


############################################################################


column = randint(0, 7)
chess[0][column] = 1
Path.append([0, column])

if solve(1):
    printpath(chess)
else:
    print "Solution Does Not Exsists"
