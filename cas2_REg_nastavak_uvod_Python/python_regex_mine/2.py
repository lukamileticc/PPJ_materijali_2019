import sys
import re

if len(sys.argv) < 2:
	sys.exit("./2.py filePath")

pattern = re.match(r".+\.txt",sys.argv[1],re.I)
#re.I ignore case

if pattern is None:
	exit("Fajl mora biti .txt")


ri = re.compile(r'(?i)(\b[A-Za-z]+\b)\s+\1')

try: 
#	with open(sys.argv[1],"r") as f:
#	datoteka = f.read()
	f = open(sys.argv[1],"r")
except IOError:
	sys.exit("Fajl ne postoji")


while True:
	linija = f.readline()
	if linija == "": break #stigli smo do EOFA
	
	match = ri.search(linija)
	
	if match is not None:
		
		print("Poklapanje: %s\t groups: %s"%(match.group(),match.groups()))
		
		
		print ("Linija bez ponavljanja: " + ri.sub('bilo sta', linija))


f.close()
