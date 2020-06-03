import sys

x = int(input("Unesite broj: "))

print(x/2,x%2)

if x > 1000:
	print("Broj je veci od hiljadu")
else:
	if x % 2 == 1:
		print("Broj je neparan")
	else:
		print("Broj je paran")

	
	print("Broj je manji od 1000")


print("Ovo se stampa u svakom sl") 
