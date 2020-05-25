from sklearn.datasets import load_breast_cancer
from pandas import DataFrame
from matplotlib import pyplot
pyplot.rcParams['font.family'] = 'IPAPGothic'
from pandas.plotting import scatter_matrix

breast_cancer = load_breast_cancer()
X = breast_cancer.data
Y = breast_cancer.target
feature_names = breast_cancer.feature_names

# X = X[:, :10]
columns = ['半径', 'テクスチャ', '周囲の長さ', '面積', 'なめらかさ', 'コンパクト性', 'へこみ', 'へこみの数', '対称性', 'フラクタル次元']
df = DataFrame(data = X[:, :10], columns = columns)
df['目的変数'] = Y

colors = ['red' if v == 0 else 'blue' for v in Y]

axes = scatter_matrix(df[columns], figsize = (20, 20), diagonal = 'kde', c = colors)

pyplot.show()
# print(df.tail())
# print(df.describe())

# print(feature_names)
