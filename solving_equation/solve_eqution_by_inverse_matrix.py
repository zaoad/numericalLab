from EqToMat import toMatrix

res = []

def getMinor(mat, r,c):
    ret = [row[:c] + row[c+1:] for row in (mat[:r]+mat[r+1:])]
    return ret

def getDeternminant(mat):
    if len(mat) == 2:
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]

    ret = 0
    for i in range(len(mat)):
        ret += ((-1)**i) * mat[0][i] * getDeternminant(getMinor(mat, 0, i))
    return ret

def SolveFor(m, b, D, col):
    tm = []
    for i in range(len(m)):
        tm.append(m[i][col])
        m[i][col] = b[i]

    ans = getDeternminant(m)
    res.append(ans/D)
    for i in range(len(m)):
        m[i][col] = tm[i]

if __name__ == '__main__':
    matrix, b, symbols = toMatrix("in1.txt")
    outFile = open("out1.txt", 'w')
    D = getDeternminant(matrix)
    n = len(matrix)
    print(matrix)
    for x in range(n):
        SolveFor(matrix, b, D, x)

    print(res)

    if res != -1:
        outFile.write("Answers:\n")
        for i in range(len(res)):
            outFile.write(symbols[i] + " : " + str(res[i]))
            outFile.write("\n")