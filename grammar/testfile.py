# i = 12
# j = 13 >= i
# k = gen(14, 15)
# l = not not not not not not j
# $END$

# a=5; a+=1; b=a+1; print(a,b)
# class C:
#     pass

# del [C][0]
# print(C)

# a = 1

# def change_a():
#     global a
#     a += 2

# for i in range(1, 10):
#     a = i

# print(a)

from dataclasses import dataclass


def myfunc1():
  x = "John"
  def myfunc2():
    def myfunc3():
        nonlocal x
    x = "hello"
  myfunc2()
  return x

print(myfunc1()) 

def func(a, /):
   print(a)

i = 2
while i < 5:
   i += 1
   if i == 5: 
      break
else:
   print(i)
print(i)

dziadostwo = [1, 2, 4]
dicta = {'meow': 1}

def get_dziadostwo():
   global dziadostwo
   return dziadostwo

@dataclass()
class a:
   val: int

b = a(1)
match i:
    case b.val:
        print('dopasowion')