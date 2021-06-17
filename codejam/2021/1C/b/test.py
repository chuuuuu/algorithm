

def check(x):
  y = str(x)
  for i in range(1, int(len(y)/2)+1):
    y = str(x)
    n = y[:i]
    flag = True
    while len(y) != 0:
      # print(n)
      l = len(n)
      if y[:l] != n:
        flag = False
        break
      y = y[l:]
      n = str(int(n)+1)
      
    if flag:
      print(f', {x}')
      return

# check(1001)

for i in range(1, int(2e18)):
  check(i)