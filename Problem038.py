import cv2
a=input("Enter the image path: ")
img=cv2.imread(a)
b=input("Enter the image title: ")
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
show=cv2.imshow(b,img)
cv2.waitKey(0)
cv2.destroyAllWindows()
c=input("Enter the name to save the image: ")
cv2.imwrite(c,img)
name="Mohit"
print(f"Image saved successfully by {name}.")