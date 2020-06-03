import re,sys

poruka = "Odakle dolazi dobro  da je i stigao dovde!"

matcher = re.match(r'(?i)\w*',poruka)

if matcher is not None:
	print(poruka[matcher.start():matcher.end()])
#isto kao
	print(matcher.group())
else:
	print("Tekst sa pocetka niske ne odgovara reglurano izrazu")

m1 = re .search(r'\b(d([a-z]+))',poruka,re.S | re.I)

if m1 is not None:
	print (m1.group() )
	print (poruka[m1.start():m1.end()])
	print (m1.group(1,2))
	print (m1.groups())

reci = re.findall(r'\b(d([a-z]*)(\s))',poruka)
print("FINDALL",reci)


print(re.sub(r"\b(d(?P<rec>[a-z]+))",r"\2-\1",poruka))


str = "hocemo na basket?"
print(str.replace("basket","FUDBAL"))
