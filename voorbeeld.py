import matplotlib.pyplot as plt
execfile("init.py")
execfile("coinciding_partials.py")
execfile("dissonantie_berekening.py")

def voorbeeld(welk):
	if welk == 0:
		fr = f
		am = a
		label_cp = "zaagtand, samenvallende partialen"
		label_dc = "zaagtand, dissonantie curve"
	if welk == 1:
		fr = fg
		am = ag
		label_cp = "gamelan, samenvallende partialen"
		label_dc = "gamelan, dissonantie curve"
	(x, y) = coinc_prtl_calc(fr, am)
	plt.plot(x, y)
	plt.xlabel("interval grootte ->")
	plt.ylabel("n samenvallende partialen ->")
	plt.title(label_cp)
	plt.show()
	(interv, diss) = sorteer(x, y)
	cp_tonen = stem_cp(interv, 8)



	(x, y) = diss_calc(fr, am)
	plt.plot(x, y)
	plt.xlabel("interval grootte ->")
	plt.ylabel("dissonantie ->")
	plt.title(label_dc)
	plt.show()
	(interv, diss) = sorteer(x, y)
	dc_tonen = stem_dc(interv, 8)

	print "samenvallende partialen, 7 tonen:"
	print cp_tonen

	print "dissonantie curve, 7 tonen:"
	print dc_tonen

voorbeeld(0)
voorbeeld(1)
