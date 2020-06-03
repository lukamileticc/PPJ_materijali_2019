s = set("magija")
print (s)

b= ['magija', "pokus", 'abrakadabra', 'magija', "hokus" ]

print(set(b))


if 'f' not in s:
	s.add('f')
else:
	s.remove('f')

c = set('mudro')
print("\n",s,"\n",c)

print(s&c)
print(s.intersection(c))

print(s | c)
print(s.union(c))

print(s - c)
print(s.difference(c))

print(s^c)
print(s.symmetric_difference(c))
