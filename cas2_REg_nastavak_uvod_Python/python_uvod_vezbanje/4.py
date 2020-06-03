a = 1,2,3,4,5
print(a)

l = list((1,2,3))
print(l)

l2 = [7.2 , 4 , "sandra!","python"]
print(l2)

print(l + l2)

b = l2[:]
print(b)

b[:0] =["na","pocetak"]

print(b)

if "pocetak" in b:
    b.remove("pocetak")
else:
    print("pocetak se ne nalazi vise u b " + b)

b.pop()
print(b)

print(b.pop(0))
print(b)


c = list((-1,3,100,-44))
print(c)

c.sort( reverse=True)
print(c)

b.append("lukindra")
b[0:2] = []
print(b)
b.sort(key = len,reverse = True)
print(b)

