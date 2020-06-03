import sys

pitanja = ['ime','prezime','mesto']
odgovori = ['Aleksandarkoooo','Peric','Beograd']

print(*zip(pitanja,odgovori))

for a,b in zip(pitanja,odgovori):
	#print (a,b,"\n")
	print("Tvoje {0}: Moje {0} je {1}".format(a,b))

print('\n')
for a,b in zip(pitanja,odgovori):
	print("Tvoje %s: Moje %s je %s"%(a,a,b))

print("\n")
for a,b in zip(pitanja,odgovori):
	print("Tvoje %(pit)s: Moje %(pit)s je %(odg)s"%{"pit":a,"odg":b})


