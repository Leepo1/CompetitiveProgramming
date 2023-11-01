def solution(x, y):
    m = int(x)
    f = int(y)
    rounds = 0
    while (m!=1 or f!=1):
        if m<=0 or f<=0:
            return 'impossible'
        if m>f:
            if f==1:
                rounds+=m-1
                break
            rounds += (m//f)
            m %= f
        else:
            if m==1:
                rounds+=f-1
                break
            rounds += (f//m)
            f %= m
    return str(rounds)


