import sys
import re


if len(sys.argv) < 2:
	sys.exit("File Path")

m = re.match(r".*\.txt",sys.argv[1])
if m is None:
	sys.exit("Nije txt datoteka")

try:
	with open(sys.argv[1],"r") as f:
		datoteka = f.readlines()
except IOError:
	sys.exit("fajl ne postoji " ,sys.argv[1])


ri = re.compile(r"(?i)(\b[a-zA-z\d]+\b)\s+\1")

for linija in datoteka:
	
	match = ri.findall(linija)
	if match is not None:
		print("Poklapanja: %s\t groups = %s"%(match,match))
		print("Linija bez ponavljanja: " + 
		ri.sub(r'\1',linija))


