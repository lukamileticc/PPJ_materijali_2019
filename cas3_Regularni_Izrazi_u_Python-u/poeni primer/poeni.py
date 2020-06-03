import sys,re

if len(sys.argv) < 2:
	sys.exit("argumenti")

matcher = re.match(r".*\.html$",sys.argv[1])
if matcher is None:
	sys.exit("mora biti .html fajl")

try:
	with open(sys.argv[1],"r") as f:
		podaci = f.read()
except IOError:
	sys.exit("File open failed")

studenti = []
poeni = []

ri = re.compile(r"<tr>"
+ r"\s*<td>\s*(?P<ime>[A-Za-z]+( [A-Za-z]+)+)\s*</td>"
+ r"\s*<td>\s*(?P<zadaci>\d|[1-9]\d|100)</td>"
+ r"\s*<td>\s*(?P<teorija>\d|[1-9]\d|100)</td>"
+r"\s*</tr>")


m = ri.search(podaci)

while m is not None:
	
	studenti.append(m.group("ime"))
	
	ukupno = int(m.group('zadaci')) + int(m.group('teorija'))

	poeni.append(ukupno/2)
	
	m = ri.search(podaci,m.end())



sortirani = sorted(zip(poeni,studenti))
sortirani.reverse()

print(sortirani)
i = 1

try:
	with open("fajl.txt","w") as f:
		for p,s in sortirani:
			f.write(str(i) + ". " + s + ", " + str(p) + "\n")
			i = i +1

except IOError:
	sys.exit("file creat failed")
	
