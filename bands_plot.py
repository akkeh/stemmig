import numpy as np
import matplotlib.pyplot as plt
'''
2 tones with f1 and f2 are:
-	perfectly consonant if f1 == f2 (f1 +/- 5% = f2)
-	consonant if difference between f1 and f2 > critical bandwih
-	dissonant if difference between f1 and f2 is between 5 and 50%
-	maximally dissonant if difference is 1/4 of critical bandwidth

calculation of critical bandwith:
	ERB = 24.7 * (4.37 * f/1000 + 1)
		-	ERB; 	bandwith [Hz]
		-	f; 		frequency [Hz]
'''

prtl_count = 10
base_freq = 100

N = (prtl_count+1) * base_freq
interval = (3/2.0)

diss_curve = [0, 0.7, 1, 0.9, 0.8, 0.6, 0.4, 0.2, 0.1, 0, 0, 0]

def interp(perc):
	u_val = diss_curve[int(perc_CB/10+1)]
	d_val = diss_curve[int(perc_CB/10)]
	val = d_val + ((u_val-d_val) * (perc/10-int(perc/10)))
	return val
	

p1	=	np.array([])
p2	=	np.array([])
for i in range(prtl_count):
	p1 = np.append(p1, base_freq * (1+i))
	p2 = np.append(p2, (base_freq*interval) * (1+i))

s1 = np.arange(N*1.5)
s1.fill(0.0)
index = 1
for i in p1:
	val = 0.0
	ERB = 24.7 * (4.37 * i/1000 + 1)
	for n in range(int(-ERB/2), int(ERB/2)):
		perc_CB = (100 * abs(n)/(ERB/2))
		val = interp(perc_CB) / index;
		if i+n < N*1.5:
			s1[i+n] = (s1[i+n] + val)
	index+=1


s2 = np.arange(N*1.5)
s2.fill(0.0)
index = 1
for i in p2:
	val = 0.0
	ERB = 24.7 * (4.37 * i/1000 + 1)
	for n in range(int(-ERB/2), int(ERB/2)):
		perc_CB = (100 * abs(n)/(ERB/2))
		val = -interp(perc_CB) / index
		if i+n < N*1.5:
			s2[i+n] = (s2[i+n] + val)
	index+=1

plt.axis([0, N, -1, 1])
plt.plot(np.arange(N*1.5), s1, np.arange(N*1.5), s2 );
plt.show()
