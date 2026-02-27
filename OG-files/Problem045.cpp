#include<iostream>
using namespace std;
class Rectangle{
    public:
        int length;
        int bredth;
        int area(int length, int bredth){
            return length*bredth;
        }
        int perimeter(int length, int bredth){
            return 2*(length+bredth);
        }
};
int main(){
    Rectangle rec;
    cout<<"Enter the length, bredth one after another: ";
    cin>>rec.length>>rec.bredth;
    int ar=rec.area(rec.length,rec.bredth);
    int pr=rec.perimeter(rec.length,rec.bredth);
    cout<<ar<< " "<<pr;
    return 0;

}