def interleave(s, t, res, i, j, lis):
    if i == len(s) and j == len(t):
        lis.append(res)

    if i < len(s):
        interleave(s, t, res + s[i], i + 1, j, lis)
    if j < len(t):
        interleave(s, t, res + t[j], i, j + 1, lis)

if __name__ == '__main__':

    l = []
    s = "23"
    t = "456"
    interleave(s, t, "", 0, 0, l)
    print(l)