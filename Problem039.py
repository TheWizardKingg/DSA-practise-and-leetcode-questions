import pandas as pd 
dict1={'Name':['Tom','nick','krish','jack'],
        'Age':[20,21,19,18],
        'Marks':[85,86,84,88]}
a=pd.DataFrame(dict1)
b=a.loc["Age"[0]]
print(b)
# print(a)