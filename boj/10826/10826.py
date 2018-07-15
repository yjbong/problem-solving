fib=list()
fib.append(0)
fib.append(1)
n=input()
for i in range(2,n+1):
	fib.append(fib[i-1]+fib[i-2])
print(fib[n])