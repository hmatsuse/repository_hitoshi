d = { 'Hendrix':'1942', 'Allman':'1946', 'King':'1925', 'Clapton':'1945', 'Johnson':'1911', 'Berry':'1926', 'Vaughan':'1954', 'Cooder':'1947', 'Page':'1944', 'Richards':'1943', 'Hammett':'1962', 'Cobain':'1967', 'Garcia':'1942', 'Beck':'1944', 'Santana':'1947', 'Ramone':'1948', 'White':'1975', 'Frusciante':'1970', 'Thompson':'1949', 'Burton':'1939', }

def d_sort(d):
    d_list = []
    for k,v in d.items():
        d_list.append([k, v]) 
    i = 0
    for k,v in d_list:
        d_list[i][0] = v
        d_list[i][1] = k
        i += 1
    return (sorted(d_list,key = lambda x:(x[0], x[1])))

for k,v in d_sort(d):
    print(v)
