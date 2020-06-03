
a = "Moze i ovako"
b = ""

for x in a:
  if x in ('a','e','i','o','u'):
    b = b + x.upper()
  elif not x.isalpha() :
    b = b + '-'
  else:
    b = b+x

print(a)
print(b)


for i in range(0,11,1):
	print(2,"^",i,"=",2**i, end = "\n")


#stampamo svaki element liste u novom redu
l = [ 'ovde','tamo', 'negde','svuda']

for x in l:
	print(x)

print()

for x in l[:]:
	l.insert(0,x)

print(l)

for i in range(len(l)):
	if i != len(l) -1:
		print(l[i], end = ", ") 
	else:
		print(l[i],end ="\n\n")








