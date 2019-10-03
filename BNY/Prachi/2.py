def c(s):

	m = [0]*26
	if len(s) == 1:
		return 1;

	unique = 0

	for i in range(len(s)):
		if m[ord(s[i]) - ord('a')] == 0:
			unique += 1
		m[ord(s[i]) - ord('a')] += 1
		if unique>2:
			return 0

	if unique == 1:
		return 1

	for i in range(len(s) - 1):
		if s[i] == s[i+1]:
			return 0

	return 1

N = int(input())
ans = 0
for i in range(N):
	s = input()
	ans += c(s)
print(ans)