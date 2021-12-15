register = [0] * 100
ptr = 0
universal = 0

Alphabet = {
	0:'a',
	1:'b',
	2:'c',
	3:'d',
	4:'e',
	5:'f',
	6:'g',
	7:'h',
	8:'i',
	9:'j',
	10:'k',
	11:'l',
	12:'m',
	13:'n',
	14:'o',
	15:'p',
	16:'q',
	17:'r',
	18:'s',
	19:'t',
	20:'u',
	21:'v',
	22:'w',
	23:'x',
	24:'y',
	25:'z',
	-1:' '
}
def main():
	global ptr, register
	print("Enter 'bee' for help")
	while(1):
		beeString = str(input())
		if(len(beeString) != 3):
			raise ValueError('Input must have form "bee" ')
		if beeString == "bEe":
			ptr -= 1
		elif beeString == "beE":
			ptr += 1
		elif beeString == "BeE":
			register[ptr] += 1
		elif beeString == "BEe":
			register[ptr] -= 1
		elif beeString == "Bee":
			print(register[ptr])
		elif beeString == "BEE":
			print(register)
			for i in range(len(register)):
				print("", Alphabet[register[i]],end= " ")
			print()
		elif beeString == "bee":
			print("\nB refers to current register, b refers to ptr location")
			print("eE increments, Ee decrements")
			print("BEE prints all registers, Bee prints current register\n")
if __name__ == '__main__':
	main()
