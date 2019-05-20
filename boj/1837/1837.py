isNotPrime=list()

for i in range(0,1000001):
	if i==0 or i==1: isNotPrime.append(True)
	else: isNotPrime.append(False)

for i in range(0, 1000001):
	if isNotPrime[i]==False:
		for j in range(i*2, 1000001, i): isNotPrime[j]=True

# get input(p,k)
c=raw_input().split()
p=int(c[0])
k=int(c[1])

# check if p has a prime factor which is lesser than k
good=True
for i in range(0, k):
	if isNotPrime[i]==False and p%i==0:
		good=False
		ans=i
		break

if good==True:
	print('GOOD')
else:
	print('BAD %d' % ans)
