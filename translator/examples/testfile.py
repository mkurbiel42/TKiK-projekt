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

while i < 10:
    i += 1

raise Exception(1)
