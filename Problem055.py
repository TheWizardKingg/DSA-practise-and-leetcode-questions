import numpy as np
list=[1,2,3,4,5,6,7,8,9,10,11,12]
array=np.array(list)
print(array) #1D array
a=array.reshape(3,4)
b=array.reshape(4,3)
c=array.reshape(2,6)
d=array.reshape(1,12)
print(a)# 2D array
print(b)# 2D array
print(c)# 2D array
print(d)# 1D array
list2 = np.array([[1,2,3],
                [4,5,6]])

list3 = np.array([10,20,30])
print(list2+list3)
print(list2-list3)
print(list2*list3)
print(list2/list3)

var1=list3.reshape(3,1)+list2.reshape(3,2)
print(var1)

list4 = np.random.randn(5,3)
list5 = np.random.randn(5,1)
print(list4.T@list5)
list6 = np.array([1,2,3,4,5])
print(np.std(list6))
print(np.mean(list6))
print(np.max(list6))
print(np.min(list6))
print(np.sum(list6))
list7 = np.array([[1,2,3],
                [4,5,6]])
print(np.std(list7,axis=0))
print(np.mean(list7,axis=0))
print(np.max(list7,axis=0))
print(np.min(list7,axis=0))
print(np.sum(list7,axis=0))

#all numpy operations are faster than normal python operations






