import sys

print(sys.argv , "\n")


if len(sys.argv) == 1:
	exit("Nedovoljno argumenata")

try:

	f = open(sys.argv[1],"r")

except IOError:
	exit("Neupsenoo! "+ sys.argv[1])


sadrzaj = f.read()
print(sadrzaj)

f.close()


try:

	f = open("kopija" + sys.argv[1],"w")
except IOError:
	exit("Neupseno otvaranje datoteke " + "kopija " + sys.argv[1])


f.write(sadrzaj)

f.close()
