import numpy as np
f = np.arange(10)
f = f[1::]
a = f[::-1]
f = np.multiply(f, 100)

f2 = np.random.randint(1, 10, size=10)
index = 0

for i in f2:
	f2[index] = f2[index] * (index)
	print(f2[index])
	index+=1

f2 = f2[1::]

f2 = np.multiply(f2, 100)

