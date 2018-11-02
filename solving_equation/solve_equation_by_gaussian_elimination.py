from EqToMat import toMatrix

outFile = open("out2.txt", 'w')

def PrintMatrixFile(m):
    for i in range(len(m)):
        for j in range(len(m)):
            outFile.write(str(m[i][j]))
            outFile.write(" ")
        outFile.write("\n")
    outFile.write("\n")

def swap_row(i, j, m):
    for k in range(len(m)):
        temp = m[i][k]
        m[i][k] = m[j][k]
        m[j][k] = temp

def forward_elimination(mat, matInv, row, col):
    if row >= len(mat): return

    pivot = mat[row][col]

    for i in range(len(mat)):
        matInv[row][i] = matInv[row][i] / pivot
        mat[row][i] = mat[row][i] / pivot

    if row > col:
        for i in range(len(mat)):
            matInv[row][i] = matInv[row][i] - matInv[col][i]
            mat[row][i] = mat[row][i] - mat[col][i]

    forward_elimination(mat, matInv, row + 1, col)

def backward_elimination(mat, matInv, row, col):
    if row < 0: return

    if row < col:
        pivot = mat[row][col]
        for i in range(len(mat)):
            matInv[row][i] = matInv[row][i] - pivot * matInv[col][i]
            mat[row][i] = mat[row][i] - pivot * mat[col][i]

    backward_elimination(mat, matInv, row - 1, col)

def partial_pivot(row):
    for i in range[row, len(mat)]:
        if mat[i][row] != 0:
            swap_row(i, row)
    return 0

def solve(mat, matInv):
    for i in range(len(matInv)):
        for j in range(len(matInv)):
            if i==j:
                matInv[i][j] = 1


    for i in range(len(mat)):
        if mat[i][i] == 0:
            if partial_pivot(i) == 0:
                return 0

    for row in range(len(mat)):
        forward_elimination(mat, matInv, row, row)

    for row in range(len(mat)):
        backward_elimination(mat, matInv, row, row)

    print(matInv)
    return 1

if __name__ == '__main__':
    mat, b, symbols = toMatrix("in2.txt")

    outFile.write("\nThe Matrix Is:\n")
    PrintMatrixFile(mat)

    matInv = [[0 for x in range(len(mat))] for y in range(len(mat))]

    print(mat)
    poss = solve(mat, matInv)

    if poss == 0:
        outFile.write("\nNo Solution\n")
        exit(0)

    outFile.write("\nThe Inverse Matrix Is:\n")
    PrintMatrixFile(matInv)

    res = []

    for i in range(len(mat)):
        res.append(0)

    for i in range(len(mat)):
        for j in range(len(mat)):
            res[i] += matInv[i][j] * b[j]


    if res != -1:
        outFile.write("Answers:\n")
        for i in range(len(res)):
            outFile.write(symbols[i] + " : " + str(res[i]))
            outFile.write("\n")