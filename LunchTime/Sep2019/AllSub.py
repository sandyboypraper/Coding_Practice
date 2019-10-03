from collections import Counter
t = int(input())

for _ in range(t):
	a = input()
	b = input()

	mapp = Counter(b)
	
	ba = ""
	flag = 0

	for i in range(len(a)):
		if mapp[a[i]]>0:
			ba += a[i]
			mapp[a[i]] = mapp[a[i]] - 1
		else:
			print("Impossible")
			flag = 1

	if flag == 1:
		continue

	bacchi = ""

	for i in mapp:
		while mapp[i]>0:
			bacchi += i
			mapp[i] = mapp[i] - 1

	ans = ""

	# print(bacchsi)

	# print(ba)

	for i in range(len(bacchi)):
		if ba[0] < bacchi[i]:
			ans = bacchi[0:i] + ba + bacchi[i:len(bacchi)]
			break

	if ans == "":
		ans = bacchi + ba

	print(ans)
