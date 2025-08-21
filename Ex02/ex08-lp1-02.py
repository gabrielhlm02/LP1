n1 = int(input('Insira um valor: '))
n2 = int(input('Insira outro valor: '))

for i in range(min(n1, n2), max(n1, n2)+1):
	print(i)
