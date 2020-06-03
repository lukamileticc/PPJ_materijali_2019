x = 3
y = 10.51

#stampamo tipove promenljivih
print( type(x))
print( type(y))

print(x + y)

print(y**x)

print(y // x)
print(y / x)

print(y % x)

print(float(x))
print(int (y))


z = complex(x,y)
print(type(z))
print(z)

print(z + x)

print(z + 20j)
print(z + complex(1,x))

print(z.real , z.imag)

print(abs(z)) # sqrt(z.real**2 + z.imag**2)
