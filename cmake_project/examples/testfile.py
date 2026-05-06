i=1
j=2
k=3
def get(i):
    g=i+1
    add(14,15)
    def inside(j):
        nonlocal g
        # komentarz here
        return g/2
    return 1

def add(i, j):
    return i + j