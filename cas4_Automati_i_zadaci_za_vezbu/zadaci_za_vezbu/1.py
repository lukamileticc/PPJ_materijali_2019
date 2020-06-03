import sys,re


if len(sys.argv) != 2:
	sys.exit("arguments failed")


matcher = re.match(r'^[\w_-]+\.stn$',sys.argv[1])

if matcher is None:
	sys.exit("datoteka mora biti ekstenzije .stn")


try:
	with open(sys.argv[1],"r") as f:
		fajl = f.read()
except IOError:
	sys.exit("file open failed")


uzorak = re.compile(r'{(.*?),\.NE\+([a-z]+):[0-9][a-z]}',re.S)


zamena = uzorak.sub(r"<\2>\1</\2>",fajl)

try:
	with open(sys.argv[1][:-3] + "xml","w") as fxml:
		fxml.write("<xml>\n")
		fxml.write(zamena)
		fxml.write("\n</xml>")

except IOError:
	sys.exit('file open and write failed')
