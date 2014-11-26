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
		- ERB; bandwith [Hz]
		-	f; frequency [Hz]

'''

def present2(arr, val):
	aanw = 0
	for i in arr:
		if i == val:
			aanw = 1
	return aanw

def p_plot(prtls, amplit):
	ampl = np.arange(max(prtls))
	ampl.fill(0)
	index = 0
	prtl = 0
	for i in prtls:
		val = amplit[index]
		prtl+=1
		ampl[i] = val
		index+=1

#	plt.plot(range(int(max(prtls))), ampl)
#	plt.show()
	return ampl


