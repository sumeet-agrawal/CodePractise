#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box{
//l,b,h are integers representing the dimensions of the box
private:
    int l,b,h;
// The class should have the following functions : 

// Constructors: 
// Box();
public:
Box(){
    l = b = h = 0;
}
// Box(int,int,int);
Box(int length, int breadth, int height){
    l = length;
    b = breadth;
    h = height;
}
// Box(Box);
Box(Box &box){
    l = box.getLength();
    b = box.getBreadth();
    h = box.getHeight();
}


// int getLength(); // Return box's length
int getLength(){
    return l;
}
// int getBreadth (); // Return box's breadth
int getBreadth(){
    return b;
}
// int getHeight ();  //Return box's height
int getHeight(){
    return h;
}
// long long CalculateVolume(); // Return the volume of the box
long long CalculateVolume(){
    return (long)l*(long)b*(long)h;
}

//Overload operator < as specified
//bool operator<(Box& b)
bool operator<(Box& b){
    if(l<b.getLength()){
        return true;
    }
    else if(l>b.getLength()){
        return false;
    }
    else{
        if(this->b<b.getBreadth()){
            return true;
        }
        else if(this->b>b.getBreadth()){
            return false;
        }
        else{
            if(h<b.getHeight()){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
friend ostream& operator<<(ostream& out, Box& B);
};

ostream& operator<<(ostream& out, Box& B){
    out<<B.getLength()<<' '<<B.getBreadth()<<' '<<B.getHeight();
    return out;
}
