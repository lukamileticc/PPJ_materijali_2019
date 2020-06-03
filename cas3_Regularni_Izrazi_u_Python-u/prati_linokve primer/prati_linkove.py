import sys,re

def obradi_datoteke(dat):

	obradjene_datoteke.append(dat)

	try:
		with open(dat, "r") as f:
			podaci = f.read()
	except IOError:
		sys.exit("File open failed")

	ri = re.compile(r'<a\s+href\s*=\s*"(.*?)">(.*?)</a>',re.S | re.I)


	m = ri.search(podaci)
	#ili for m in ri.finditer(podaci)!
	while m is not None:
		
		url = m.group(1)
		if url not in obradjene_datoteke:
			obradi_datoteke(url)

		m = ri.search(podaci,m.end())
	
#main 
if len(sys.argv) > 1:
	pocetna = sys.argv[1]
else :
	pocetna = "indeks.html"

obradjene_datoteke =[]
obradi_datoteke(pocetna)

for di in obradjene_datoteke:
	print(di)
