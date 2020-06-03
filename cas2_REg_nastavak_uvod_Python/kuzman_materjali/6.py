import sys

lokal = {"Luka":10,"zika":1}

print(sorted(lokal.keys()))

print(lokal["Luka"])

print(lokal.get('Laza'))


print(*zip(lokal.keys(),lokal.values()))

print(('zika',1) in zip(lokal.keys(),lokal.values()))


d = dict((x,x*2) for x in range(4))
print(d)
