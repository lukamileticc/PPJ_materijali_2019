import sys,re


autor = False
godina = False
cena = False
izdavac = False


naslov = None


if len(sys.argv) < 2:
	sys.exit("arguments")


for arg in sys.argv[1:]:
	if arg == "-a":
		autor = True
	elif arg == "-c":
		cena = True
	elif arg == "-g":
		godina = True
	elif arg == "-i":
		izdavac = True
	else:
		naslov = arg;

if naslov is None:
	sys.exit("Jedan argument mora biti naslov knjige")


try:
	with open("knjige.xml","r") as f:
		datoteka = f.read()
except IOError:
	sys.stderr.exit("file pen failed")


ri = re.compile(r'<knjiga\s+rbr\s*=\s*"(?P<rbr>[0-9]+)"\s*>\s*'
	+r"(?=.*?<naslov>\s*(?P<naslov>.*?)\s*</naslov>)"
	+r"(?=.*?<autor>\s*(?P<autor>[A-Z][a-z]+(?:\s+[A-Z][a-z]+)+)\s*</autor>)"
	+r'(?=.*?<cena\s+valuta\s*=\s*"(?P<valuta>rsd|eur)">\s*(?P<cena>[1-9][0-9]*)\s*</cena>)'
	+r"(?=.*?<izdavac>\s*(?P<izd>.*?)\s*</izdavac>)"
	+r"(?=.*?<godina_izdanja>\s*(?P<godina>[0-9]+)\s*</godina_izdanja>)"
	+r".*?</knjiga>", re.S)	



biblioteka ={}

for m in ri.finditer(datoteka):

	biblioteka[m.group('rbr')] = [m.group('naslov'), m.group('autor'),m.group('godina'),m.group('izd')]

#	print(biblioteka[m.group('rbr')])

vrednosti = None
for (k,v) in biblioteka.items():
	if v[0] == naslov:
		vrednosti = v[1:]

if vrednosti is None:
	sys.exit("Ne postoji knjiga sa naslovom")

if autor:
	print (vrednosti[0])
if cena:
	print (vrednosti[2])
if izdavac:
	print ( vrednosti[3])
if godina:
	print (vrednosti[1])

if(autor or godina or cena or izdavac) == False:
	for v in vrednosti:
		print (v)	












