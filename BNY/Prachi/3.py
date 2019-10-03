MOD = 1000000007
f = [0]*10000007
f_i = [0]*103
def modExpo(x , y):
	if y == 0:
		return 1

	p = modExpo(x, y // 2) % MOD 
	p = (p * p) % MOD 
  
	if(y % 2 == 0) : 
		return p  
	else :  
		return ((x * p) % MOD) 


f[0] = 1
f_i[0] = 1

for i in range(10000000):
	at = i+1
	f[at] = (f[at-1]*at)%MOD
for i in range(100):
	at = i+1
	f_i[at] = modExpo(f[at] , MOD -2)
	# print(str(at)+" "+str(f[at])+" "+str(f_i[at]))

K = int(input())
num = [int(x) for x in input().split()]
w = sum(num) - K

sol = f[w]

# print(w)
# print(f_i[4])
# print(f_i[3])

for i in range(K):
	if num[i] != 1:
		sol = ((sol*f_i[num[i]-1])%MOD)%MOD

print(sol)

