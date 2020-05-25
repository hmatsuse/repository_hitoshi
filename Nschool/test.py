# word = "Python"
# print(f"'{word:>10}'")

# letters = ['a', 'b', 'c']
# print(letters)
# # letters.clear()
# # print(letters)
# print('a' in letters)
# print('z' in letters)
# letters.insert(3, 'd')
# print(letters)
# letters.remove('a')
# print(letters)
# a = [1,2,3]
# b = a.copy()
# print(a)
# print(b)
# b[0] = 2
# print(a)
# print(b)
# # print(id(a) == id(b))

# print(a is b)

# c = [a, b]
# print(c)
# students = {'taro' : 'man', 'yuji' : 'man', 'keito' : 'woman'}
# print(students.values())
# print(students.keys())
# print(students.items())
# for k,  v in students.items():
#     print(k, v)
# print('Taro' in students)

# a = [1,2,3,4]
# b = tuple(a)
# c = (0,9,8,7)
# d = 3,6,32,21
# a[2] = 52
# print(a)
# print(b)
# print(c)
# print(d)
# print(d[2])
# a, g, h, j = d
# print(a)

# a = [1, 2, 3, 4, 45, 5, 66, 76, 1, 2, 3]
# b = set(a)
# c = list(b)
# print(a)
# print(b)
# print(c)

# a = set('naujnitgaxk')
# print(a)
# b = set('enajahdfohr')
# print(b)
# print(a - b)
# print(b - a)
# print(a | b)
# print(a & b)
# print(a ^ b)

# a = [7, 5, 32, 2]
# b = [3, 54, 6, 7]
# for i, z in zip(a,b):
#     print(i,z)

# squares = [v ** 2 for v in range(20) if v % 2 == 0]
# print(squares)

# s = (v ** 3 for v in range(20) if v % 2 == 0)
# print([x for x in s])
# print([x for x in s])
s = {'kento': 'man', 'yuko':'woman', 'yuto':'man'}
def function(alist):
    """aaa"""
    for k, v in alist.items():
        print(k, v)
print(function.__doc__)
function(s)