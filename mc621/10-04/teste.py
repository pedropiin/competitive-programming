
if __name__ == "__main__":
	n = int(input())
	string = input()
	
	content = []
	while True:
		try:
			line = input()
		except EOFError:
			break
		content.append(line)
	
	print("---------")
	print(string)
	print(content)

	for step in content[:-1]:
		temp = step.split(" ")
		if temp[1] == "Insert":
			temp2 = temp[2].split(',')
			string = string[:(int(temp2[0]) - 1)] + temp2[1] + string[(int(temp2[0]) - 1):]
		elif temp[1] == "Delete":
			string = string[:(int(temp[2]) - 1)] + string[(int(temp[2])):]
		elif temp[1] == "Replace":
			temp2 = temp[2].split(',')		
			string = string[:(int(temp2[0]) - 1)] + temp2[1] + string[(int(temp2[0])):]

	print(string)	
