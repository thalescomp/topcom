from random import randint

MAX_POINTS = 1000

for i in xrange(0, 500):
  N = randint(3, MAX_POINTS)
  print N
  points = set()
  while len(points) < N:
    a = randint(0, 2**10)
    b = randint(0, 2**10)
    points.add((a,b))

  for x,y in points:
    print x, y

N = MAX_POINTS
print N
points = set()
while len(points) < N:
  a = randint(0, 2**10)
  b = randint(0, 2**10)
  points.add((a,b))

for x,y in points:
  print x, y

print 0

