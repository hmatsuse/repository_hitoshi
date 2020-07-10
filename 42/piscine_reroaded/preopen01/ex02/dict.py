data = [['Caleb' , 24], ['Calixte' , 84], ['Calliste', 65], ['Calvin' , 12], ['Cameron' , 54], ['Camil' , 32], ['Camille' , 5], ['Can' , 52], ['Caner' , 56], ['Cantin' , 4], ['Carl' , 1], ['Carlito' , 23], ['Carlo' , 19], ['Carlos' , 26], ['Carter' , 54], ['Casey' , 2]]

def func(data):
    i = 0
    for k,v in data:
        data[i][0] = v
        data[i][1] = k
        i += 1
    d = {}
    for da in data:
        key = da[0]
        if key not in d:
            d[key] = []
        d[key].append(da[1])
    return (d)

d = func(data)
for i in d:
    if (len(d[i]) == 2):
        print(i ,":" ,d[i][0] ,',' ,d[i][1])
    else:
        print(i ,":" ,d[i][0])
