import sys

def f():
	
	print(s)
	

def g():
	global s
	print(s)
	
	s = "Hello world2"
	print(s)

	
def h():
	
	s = "zdravo svima"
	print(s)

#main
s = "Hello world"
print(s)

print("Poziv funkcije f")
f()

print("Poziv g")
g()
print("Main")
print(s)

print("poziv h")
h()
