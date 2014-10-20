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


aaname 1e partiaal als begintoon voor berekening correct??
'''

def normaliseer(i):
	return np.multiply(i, 1.0/max(i))

def rondaf(interv):
	out = np.array([])	
	for i in interv:
		out = np.append(out, round(i*100)/100)
	return out

def present(val, lijst):
	ret = 1
	for i in lijst:
		if val == i:
			ret = 0
	return ret

def stem4(interv, toonaantal):
	interv = rondaf(interv)
	count = 0
	index = 0
	out = np.array([])
	while count < round(toonaantal/2)+1:
		if present(interv[index], out):
			if interv[index] <= 1.5:
				out = np.append(out, interv[index])
				count+=1
		index+=1
	out = np.sort(out)
	kwrt_rmt = np.array([])
	count+=1
	index=1
	kwrt_rmt = np.append(kwrt_rmt, 2)
	while count < toonaantal:
		kwrt_rmt = 	np.append(kwrt_rmt, 2.0/out[index])
		index+=1
		count+=1
	out = np.append(out, kwrt_rmt[::-1])
	return out


def stem3(interv, diss, toonaantal):
	interv = rondaf(interv)
	count = 0
	index = 0
	out = np.array([])
	while count < toonaantal:
		if present(interv[index], out):
			out = np.append(out, interv[index])
			count+=1
		index+=1
	return out
'''
def stem2(interv, diss, 7):    #input: gesorteerde interv en diss lijst
	interv = rondaf(interv)
	count = 0
	index = 0
	out = np.array([])
	while count < toonaantal:

		if interv[index] < 1.5:
			out = np.append(out, interv[index])
			count+=1
		index+=1
	return np.sort(out)	
'''
def stem(interv, diss, tres):	#input: gesorteerde interv en diss lijst
	diss = normaliseer(diss)
	index = 0
	while diss[index] < tres:
		index+=1
	print index
	interv = interv[0:index]
	diss = diss[0:index]
	
	return np.sort(interv)


def sorteer(interv, diss):
	srt_int = np.array([])
	srt_diss = np.array([])
	
	for ronde in range(len(interv)):	
		index = 0
		counter = 0
		val = 1000
		for i in diss:
			if i < val:
				val = i
				index = counter
			counter+=1
		srt_int = np.append(srt_int, interv[index])
		srt_diss = np.append(srt_diss, val)
		interv = np.delete(interv, index)
		diss = np.delete(diss, index)
	return srt_int, srt_diss 



def interp(perc):
	diss_array = [0, 1, 1, 0.9, 0.8, 0.6, 0.4, 0.2, 0.1, 0, 0, 0]
	#u_val = diss_array[int(perc*10+1)]
	d_val = diss_array[int(perc*10)]
	#val = d_val + ((u_val-d_val) * (perc/10-int(perc/10)))
	return d_val

def ERB(freq):
	return (24.7 * (4.37 * freq/1000 + 1))

def diss_curve(freq, ampl):
	dc = np.arange(float(min(freq)-int(ERB(min(freq))+1)), 2*max(freq)+(2*int(ERB(max(freq))+1)))
	dc.fill(0)
	index = 0
	for i in freq:
		for n in range(int(i-ERB(i)/2), int(i+ERB(i)/2)):
			dc[n] = interp(float(abs(n-i))/(ERB(i)/2.0)) * ampl[index]
		index+=1
	return dc

def diss_calc(fr_arr, ampl):
	part = np.multiply(fr_arr, (1.0/fr_arr[0]))
	intervallen = np.array([])
	dissonantie = np.array([])
	fr = fr_arr[0]
	while fr < fr_arr[0]*2:
		temp_part = np.multiply(part, fr)
		index = 0
		val = 0.0
		dc = diss_curve(fr_arr, ampl)
		for i in temp_part:
			val = val + dc[int(i)]
			index+=1
		intervallen = np.append(intervallen, fr/fr_arr[0])
		dissonantie = np.append(dissonantie, val)
		fr += (0.05*ERB(fr))
	return intervallen, dissonantie

'''	

prtl_count = 10
base_freq = 100

N = (prtl_count+1) * base_freq
interval = (22.0/20)


	

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
'''
