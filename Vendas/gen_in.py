from random import randint

MAXIMUM = 50000

def gen_input(N, M):
  print N
  l = [randint(1, 2**30) for i in xrange(N)]
  for i in l:
    print i,
  print
  print M
  for i in xrange(M):
    a = randint(0, N / 2)
    b = randint(a + 1, N)
    print a, b

for i in xrange(0,100, 10):
  N = randint(10, MAXIMUM)
  M = randint(1, 100)
  gen_input(N, M)

gen_input(50000, 100)
print 0
