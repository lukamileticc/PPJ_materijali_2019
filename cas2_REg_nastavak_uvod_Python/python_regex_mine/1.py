import sys,re

if len(sys.argv) < 2:
	sys.exit("Nedovoljno argumenata")


uparivac = re.match(r".+\.txt",sys.argv[1],re.I)

if uparivac  is not  None:
	print("argument ispravan")
else:
	print("argument neispravan")
