from sympy import *
from itertools import cycle

def toMatrix(file):
    symbolss = set([])

    file1 = open(file, "r")
    dat = file1.read()

    dat = dat.replace(" ", "")
    dat = dat.replace("=", "-")

    for i in range(len(dat)):
        if (dat[i] >= 'a' and dat[i] <= 'z'):
            if ((i + 1) < len(dat) and ('0' <= dat[i + 1] and dat[i + 1] <= '9')):
                symbolss.add(str(dat[i] + dat[i + 1]))
            else:
                symbolss.add(dat[i])

        elif dat[i] >= 'A' and dat[i] <= 'Z':
            symbolss.add(dat[i]);

    tmp = sorted(symbolss)
    sym = tmp

    equationn = ""

    for i in range(len(sym)):
        if i != 0:
            equationn = equationn + " "
        dat = dat.replace(sym[i], "x" + str(i + 1))
        equationn = equationn + "x" + str(i + 1)

    i = 0
    gen = cycle([0])
    for elt in gen:
        if (i + 1) < len(dat) and (dat[i] >= '0' and dat[i] <= '9') and dat[i + 1] == 'x':
            dat = dat[:i + 1] + "*" + dat[i + 1:]
        if (i > len(dat)):
            break
        i = i + 1

    var = symbols(equationn)
    dat = dat.splitlines()
    eq = dat

    AMat, BMat = linear_eq_to_matrix(eq, var)
    A = AMat.tolist()
    b = []
    for temp in BMat:
        b.append(temp)
    return A, b, sym

if __name__ == '__main__':
    toMatrix("in1.txt")