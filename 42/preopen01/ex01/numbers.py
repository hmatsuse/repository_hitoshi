f = open("numbers.txt","r")
line = f.readline()

while line:
    print(line.strip().replace(',', ''))
    line = f.readline()
f.close()
