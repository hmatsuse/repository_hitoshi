import numpy

# a = numpy.array([0, 1, 2, 3])
# b = numpy.array([[0, 1, 2,], [3, 4, 5]])

# print(a)
# print(b)

# print(a.size)
# print(b.size)

# print(numpy.arange(5))
# print(numpy.arange(1, 10, 2))

# print(numpy.arange(6))
# print(numpy.arange(6).reshape(2, 3))

# print(numpy.linspace(2.0, 3.0, num = 5))
# print(numpy.linspace(2.0, 3.0, num = 5, endpoint=False))

# a, step = numpy.linspace(2.0, 3.0, num = 5, retstep=True)
# print(a)
# print(step)

# print(numpy.ones(5))
# print(numpy.ones((3, 2)))
# print(numpy.zeros(5))
# print(numpy.zeros((3, 2)))
# print(numpy.eye(5))

# a = numpy.array([2, 4, 5, 6])
# print(numpy.diag(a))

# a = numpy.array([[0, 1, 2], [3, 4, 5],[6, 7, 8]])
# print(numpy.diag(a))

# a = numpy.arange(6)
# print(a.dtype)

# a = numpy.arange(6, dtype=float)
# print(a)
# print(a.dtype)

# a = numpy.array([[1], [2, 3]])
# print(a.dtype)

a = numpy.array([0, 1, 2, 3])
# print(a)
# print(a + 1)
# print(a * 2)
b = numpy.array([4, 5, 6, 7])
# print(a + b)
# print(a * b)
# print((a + b) * 2)

# print(a == b)
# print(numpy.array_equal(a, b))
c = numpy.array([0, 1, 2, 3])
# print(numpy.array_equal(a, c))
# print(a < b)
# print(a > b)
# print(a < c)
# print(a > c)

# print(a[1])

# d = numpy.arange(9).reshape(3, 3)
# print(d)
# # print(d.shape)
# # print(d[1, 2])
# # print(d[1:3])
# # print(d[::-1])
# d[2:] = numpy.array([9, 9, 9])
# print(d)

# # print(d[1:, 1:])
# print(d[2, :])
# print(d[:, 0])

# a = numpy.arange(15)
# # print(a)
# b = numpy.array([2, 5, 6, 3, 8, 25, 1, 5, 9])
# mask = (a % 3 == 0)
# # print(a[mask])
# a[mask] = -1
# print(a)
# lst = list(range(0, 15, 2))
# print(lst)

# print(a[lst])
# print(a[numpy.arange(0, 15, 2)])

# print(numpy.argmin(b))
# print(numpy.argmax(b))

# b = numpy.arange(6).reshape(2, 3)
# print(b)
# print(b.shape)
# # print(b.sum(axis = 0))
# # print(b.sum(axis = 1))
# b0 = b.sum(axis = 0, keepdims = True)
# print(b0)
# print(b0.shape)
# b0 = b.sum(axis = 1, keepdims = True)
# print(b0)
# print(b0.shape)

a = numpy.array([4, 6, 23, 65, 7, 75, 4, 2])
print(a)
print(numpy.sort(a))
print(numpy.argsort(a))

mask = numpy.argsort(a)
print(a[mask])