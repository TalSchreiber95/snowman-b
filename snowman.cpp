#include <iostream>

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
namespace Body{
    
const vector<string> Hats  = {"     \n _===_"," ___ \n .....","  _  \n  /_\\ "," ___ \n (_*_)",};
const vector<string> Nose{",",".","_"," ",};
const vector<string> Eye {".","o","O","-",};
const vector<string> LeftArmUp {" ","\\"," "," ",};
const vector<string> LeftArmDown {"<"," ","/"," ",};
const vector<string> RightArmUp {" ","/"," "," ",};
const vector<string> RightArmDown {">"," ","\\"," ",};
const vector<string> Torso{" : ","] [","> <","   ",};
const vector<string> Base{"( : )","(\" \")","(___)","(   )",};
}


namespace ariel
{
    vector<int> check_legal (int num){
        vector<int> arr = { 0, 0, 0, 0, 0, 0,0,0};
        int digit =0;
        const int bigger_then_4_digit=4;
        const int smaller_then_1_digit=1;
        const int size =8;
        const int mud=10;    

    for (int i = 0; i < size; i++)
        {
            digit =(num%mud);
            if (digit<smaller_then_1_digit||digit>bigger_then_4_digit){  
	        	throw out_of_range{"Ilegal digit!"};
            }
            digit--;
            arr.at(size-1-i) = digit;
            num=num/mud;
        }
        return arr; 
    }  

    string  snowman(int num)
    {
        //create the megic number.
        const int H=0;
        const int N=1;
        const int L=2;
        const int R=3;
        const int X=4;
        const int Y=5;
        const int T=6;
        const int B=7;
        const int bigger_then_8_digit =99999999;
        const int smaller_then_8_digit=10000000;  

        //if number is out of range
        if (num>bigger_then_8_digit||num<smaller_then_8_digit){
            throw out_of_range{"number is out of range!"};
        }   
        vector<int> arr = check_legal(num);    

        // build the snowman's string
        string snow=" ";
        snow.append(Body::Hats.at(arr.at(H)));
        snow.append("\n");
        snow.append(Body::LeftArmUp.at(arr.at(X)));
        snow.append("(");
        snow.append(Body::Eye.at(arr.at(L)));
        snow.append(Body::Nose.at(arr.at(N)));
        snow.append(Body::Eye.at(arr.at(R)));
        snow.append(")");
        snow.append(Body::RightArmUp.at(arr.at(Y)));
        snow.append("\n");   
        snow.append(Body::LeftArmDown.at(arr.at(X)));
        snow.append("(");
        snow.append(Body::Torso.at(arr.at(T)));
        snow.append(")");
        snow.append(Body::RightArmDown.at(arr.at(Y)));
        snow.append("\n");
        snow.append(Body::Base.at(arr.at(B)));
        
        return snow ;
}

}