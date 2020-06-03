import sys

def prost(n):
	
	if(n == 2):
		return True
	if(n%2 == 0):
		return False

	for i in range(3,n//2,2):
		if(n%i == 0): return False

	return True


try:

	x = int(input("Uneiste broj "))
	if x <= 1:
		raise ValueError

except ValueError:
	sys.exit("Niste uneli odgovarajuci broj")

if prost(x):
	print("Prost")
else:
	print("Nije prost")

