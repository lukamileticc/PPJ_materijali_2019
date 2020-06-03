import sys

def fibonaci(n = 10):
		
	niz = []
	a,b = 0,1

	while a < n:
		niz.append(a)
		a,b = b,a+b
	
	return niz

def main():
	
	x = int(input("Unesite neki broj: "))

	niz = fibonaci(x)
	print(niz)
	print(fibonaci() )


#odavde pocinje program
main()
