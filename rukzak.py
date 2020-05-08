A = [3, 5, 7, 10]
S = 14
F = [0] * (S + 1)
F[0] = 1;

'''
for j in range(len(A)):
	for i in range(0, S + 1):
		if F[i] == 1:
			F[i + A[j]] = 1

print(F)
'''

F_new = F[:]
for j in range(len(A)):
	for i in range(0, S + 1):
		if i - A[j] >=0 and F[i - A[j]] == 1:
			F_new[i] = 1
	F = F_new[:]
print(F)
