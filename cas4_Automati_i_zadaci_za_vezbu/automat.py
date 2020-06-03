#!usr/lib/python3
try:
	f = open("konacni_automati.txt","r")
except IOError:
	print("Open failed")
	sys.stderr.exit(1)

linije  = f.readlines()
f.close()

def nije_komentar(l):
	return l[0] != '#' and l!='\n'
def strip(s):
	return s.strip()

linije = filter(nije_komentar,linije)
print linije


import re
azbuka = re.split(",\s*",linije[0])
azbuka = map(strip,azbuka)
print(azbuka)

stanja = re.split(",\s*",linije[1])
stanja = map(strip,stanja)
stanja = map(int, stanja)
print stanja	

pocetno_stanje = int(linije[2].strip())
print pocetno_stanje

if pocetno_stanje not in stanja:
	print ("Neispravno_pocetno stanje")
	sys.exit()
else:
	print("Okej je pocetno stanje")


zavrsna_stanja = re.split(",\s*",linije[3])
zavrsna_stanja = map(strip,zavrsna_stanja)
zavrsna_stanja = map(int,zavrsna_stanja)
print(zavrsna_stanja)

for zs in zavrsna_stanja:
	if zs not in stanja:
		print("Neispravna zavrsna stanja")
	else:
		print("Okej su zavsna stanja")


prelazi = {}
linije = map(strip,linije)

for i in range(4,len(linije)):
	stanje1, slovo,stanje2 = re.split("\s+",linije[i])

	stanje1 = int(stanje1)
	stanje2 = int(stanje2)
	if stanje1 not in stanja:
		print "failed1"
	if stanje2 not in stanja:
		print "failed3"
	if slovo not in azbuka:
		print "failed2"
	

	if (stanje1,slovo) in prelazi:
		print "Automat nije dka"
	else:
		prelazi[(stanje1,slovo)] = stanje2
	
#print stanje1 ,slovo ,stanje2

print prelazi

import sys

rec = sys.stdin.readline()
rec = strip(rec)
print rec

tekuce_stanje = pocetno_stanje
for karakter in rec:
	if(tekuce_stanje,karakter) in prelazi:
		tekuce_stanje = prelazi[(tekuce_stanje,karakter)]
	else:
		sys.exit("Greska")


if tekuce_stanje in zavrsna_stanja:
	print("Automat prihvata rec")
else:
	print("Automat ne prihvata rec")

