import cv2
a=input("Enter the image path: ")             # first you need an image in the same folder where this code sits
img=cv2.imread(a)
b=input("Enter the image title: ")
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
show=cv2.imshow(b,img)
print(img.shape())               # prints the dimensions of the image as  ->   (height, width, (blue, green, red))
cv2.waitKey(0)
cv2.destroyAllWindows()
c=input("Enter the name to save the image: ")
cv2.imwrite(c,img)
name="Mohit"
print(f"Image saved successfully by {name}.")


# reading = module.function("<file_name>")                        [file_name is fixed as per the image]
# showing = module.function("<title>",<reading>)                  [title can be anything as per user choice]
# writing/saving = module.function("<new_file_name>",<reading>)   [new_file_name can be anything as per user choice] 
# cv2.COLOR_BGR2GRAY is used to convert the image from BGR to GRAY scale
# cv2.waitKey(0) is used to keep the image window open until any key
# dude, i am a madman, did so many commits in this file already :P