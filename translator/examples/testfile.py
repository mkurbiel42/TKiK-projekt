i=1
j=2
k=3
def get(i):
    g=i+1
    add(14,15)
    def inside(j):
        nonlocal g
        return g/2
    return 1

def add(i, j):
    return i + j

class MyClass:
    i = 12345

    def f(self):
        return 'hello world'

try:
    print(x)
except NameError:
    print("Variable x is not defined")

for i in range(6):
    print(i)

day = 4
match day:
  case 6:
    print("Today is Saturday")
  case 7:
    print("Today is Sunday")
  case _:
    print("Looking forward to the Weekend")

i = 1

# asdasdad

print(abs(-1))
print(bool(10))
print(list(enumerate(['a', 'b', 'c'])))
print(list(enumerate(['a', 'b', 'c'], 4)))
print(list(filter(lambda x: x>10, [1, 5, 15, 2, 35, 10])))
print(int(10.3))
print(len([1, 3, 2, 4, 1]))
print(list(range(10)))
print(list(range(3, 15)))
print(list(range(3, 15, 3)))
print(list(range(15, 3, -3)))
print(list(map(lambda x: x*10, [1, 3, 2, 9, 4])))
print(max(1, 3, 2))
print(max([2, 4, 0]))
print(min(1, 3, 2))
print(min([2, 4, 0]))
print(list(reversed([1, 2, 3])))
print(round(4.5678))
print(round(4.5678, 2))
print(set([1, 2, 3, 2, 5, 3]))
print(str(10))
print(sum([1, 2, 3]))
print(sum([1, 2, 3], 2))

raise Exception(1)
