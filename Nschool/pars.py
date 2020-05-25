from pandas import DataFrame
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Perceptron
ppn = Perceptron(max_iter = 1000, random_state = 42)
from sklearn.metrics import accuracy_score
import numpy
from matplotlib import pyplot
pyplot.rcParams['font.family'] = 'IPAPGothic'
from mlxtend.plotting import plot_decision_regions

breast_cancer = load_breast_cancer()
X = breast_cancer.data[:, :10]
Y = breast_cancer.target

columns = ['半径', 'テクスチャ', '周囲の長さ', '面積', 'なめらかさ', 'コンパクト性', 'へこみ', 'へこみの数', '対称性', 'フラクタル次元']

df = DataFrame(data = X[:, :10], columns = columns)
df['目的変数'] = Y

X = df[['面積', 'へこみ']].values
Y = df['目的変数'].values

# print('全てのデータ数', len(Y))
# print('訓練データ数', len(Y_train))
# print('テストデータ数', len(Y_test))
# print(len(Y_test) / len(Y))

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.30, random_state = 42)

sc = StandardScaler()
sc.fit(X_train)

# print(sc.mean_)

X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_test)

train_mean = X_train_std.mean(axis = 0)
# print(train_mean)
train_std = X_train_std.std(axis = 0)
# print(train_std)

test_mean = X_test_std.mean(axis = 0)
# print(test_mean)
test_std = X_test_std.std(axis = 0)
# print(test_std)

ppn.fit(X_train_std, Y_train)
pred = ppn.predict(X_test_std)
print(pred)
print("--------------------------------------------------------------------------")
print(Y_test)
print(accuracy_score(Y_test, pred))

# グラフ表示
N = 100

sampled_X = numpy.vstack((X_train_std[:N], X_test_std[:N]))
sampled_Y = numpy.hstack((Y_train[:N], Y_test[:N]))

pyplot.figure(figsize = (12, 12))
pyplot.xlabel("面積")
pyplot.ylabel("へこみ")
pyplot.title("パーセプトロンの決定領域")

plot_decision_regions(sampled_X, sampled_Y, clf = ppn, legend = 2, X_highlight = X_test_std[:N])
pyplot.show()