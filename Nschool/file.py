numbers = [i for i in range(10)]

# f = open("numbers.txt", "w")

# for number in numbers:
#     f.write(f"{number},{number ** 2}\n")
# print(f.closed)
# f.close()
# 
# f = open("err.txt", "w")
# f.write("err")
# f.close()

with open("numbers.txt", "w") as f:
    for number in numbers:
        f.write(f"{number},{number ** 2}\n")
    # f.seek(0)
    # print(f.read())
print(f.closed)

with open("numbers.txt", "r") as f:
    lines = f.readlines()
    print(lines)
    f.seek(0)
    while True:
        
        line = f.readline()
        if line == "":
            break
        print(line, end="")
        print(line.rstrip())

with open("numbers.txt", "r") as f:
    for line in f:
        line = line.rstrip()
        splited = line.split(",")
        number = [int(i) for i in splited]
        print(f"{number[0] + number[1]}")
