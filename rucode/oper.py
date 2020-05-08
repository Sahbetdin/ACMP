#кол-во операций

def f(n):
	if n == 0:
		return 1
	else:
		index = n - 1
		sum = 1
		while (index >= 0):
			sum = sum + f(index)
			print("index = " , sum)
			index = index - 1
		#print("~~~~~~~")
		return sum

print(f(30))
