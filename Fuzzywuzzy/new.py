from fuzzywuzzy import fuzz 
from fuzzywuzzy import process 

def after_split(stringg , word):
	return stringg.split(word)


def after_split_join(stringg , data):
	
	for i in range(len(data)):
		temp = ""
		stringg = temp.join(after_split(stringg , data[i]))

	return stringg


def special_char(a):

	data = ["have", "want" , "been" , "with" , "the" , "to" , "an" , "i" , "a"]
	return after_split_join(a , data)



while True:
	a = input()
	b = input()

	# aa = special_char(a)
	# bb = special_char(b)
	# print(aa)
	# print(bb)
	print(fuzz.ratio(a.upper(), b.upper()))