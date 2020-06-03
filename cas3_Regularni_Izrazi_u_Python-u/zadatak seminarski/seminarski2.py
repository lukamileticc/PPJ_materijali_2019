import re,sys,os


homedir = 'seminarski_radovi'
studenti = {}


putanja = os.path.join(homedir,'indeksi')

try:
	with open(putanja,"r") as f:
		for linija in f.readlines():
			
			if linija[-1] == '\n':
				linija = linija[:-1]

			if re.match(r'm[mnvlri]\d{5},\s*[A-Za-z ]+',linija) is not None:
				
				info = re.split(r',\s*',linija)

				studenti[info[0]] = info[1]

except IOError:
	sys.exit("FIle open failed")



re_dir = re.compile(r'^m[mnvlri]\d{5}$')
re_file = re.compile(r'(\d+)\.(java|cpp|c|pas)$')


maks_br_zad = 0
zadaci = {}

for f in os.listdir(homedir):
	stud_dir = os.path.join(homedir,f)
	
	m = re_dir.match(f)
	if os.path.isdir(stud_dir) and m is not None:
		
		indeks = m.group()

		for sf in os.listdir(stud_dir):

			zadatak = os.path.join(stud_dir,sf)
			m = re_file.match(sf)
			if os.path.isfile(zadatak) and m is not None:
				zad = int(m.group(1))
				
				zadaci[(indeks,zad)] = m.group(2)
				if zad > maks_br_zad:
					maks_br_zad = zad




for indeks,ime in studenti.items():

	print ("\nIme:" + ime)
	
	for i in range (1,maks_br_zad):

		if(indeks,i) in zadaci:
			print("\t" + str(i) + ". " + zadaci[(indeks,i)])

		else:
			print("\t" + str(i) + ". -")
			















