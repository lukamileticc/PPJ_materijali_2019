import sys,re

def obradi_datoteke(dat):
	
	obradjene.append(dat)

	try:
		with open(dat,"r") as f:
			podaci = f.read();
	except IOError:
		sys.exit("file open failed")

	
	ri = re.compile(r'<a\s+href=\s*"(.*?)"\s*>.*?</a>',re.S | re.I)
	
	
	for m in ri.finditer(podaci):
		
		url = m.group(1)

		if url  not in statistika:
			statistika[url] = 1;
		else:
			statistika[url] += 1;

		if url not in obradjene:
			obradi_datoteke(url)

################################main:
if len(sys.argv) > 1:
	pocetna = sys.argv[1]
else:
	pocetna = "indeks.html"

obradjene = []
statistika = dict()
#statistika ={}

obradi_datoteke(pocetna)

popul = sorted(zip(statistika.values(),statistika.keys()))
popul.reverse()
print(popul)
