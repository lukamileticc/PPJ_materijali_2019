def fib(n):
	niz = []
	a,b = 0,1
	while a < n:
		niz.append(a)
		a,b = b,a+b;

	return niz


print(fib(100))

print(fib)
