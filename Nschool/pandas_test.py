import numpy
numpy.random.seed(42)
import pandas
import matplotlib.pyplot

data = numpy.random.randn(10, 5)
df = pandas.DataFrame(data, columns = ['A', 'B', 'C', 'D', 'E'])

print(df)

# # 先頭から3行
# print(df.head(3))
# # 後ろから3行
# print(df.tail(3))
# print(df.index)
# print(df.columns)
# print(df.values)
# # 統計的なデータ取得
# print(df.describe())
# print(df['B'])
# print(df[1:5])


# print(df.loc[:, ['A', 'C', 'E']])
# print(df.loc[1:5, ['A', 'C', 'E']])
# print(df.iloc[3])
# print(df.iloc[1:3, 1:3])

# mask = (df['A'] <= 0)
# print(mask)
# print(df[mask])
# print(df['A'] <= 0)
# print(df[df <= 0])

# # meanメソッドは平均を求める
# print(df.mean())
# # 平均を取る方向を指定できる
# print(df.mean(axis = 0))
# print(df.mean(axis = 1))

# # sumメソッドは和を求める
# print(df.sum())
# print(df.sum(axis = 0))
# print(df.sum(axis = 1))

df.plot(figsize = (11, 7), title = 'Test Plot', legend = True)
matplotlib.pyplot.show()
