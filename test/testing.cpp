#include <iostream>
#include <string>


using namespace std; 

string autoMorphic (int number)
{
  
  string square = to_string(number*number);
  string substring = to_string(number);
  
  if(square.find(substring) != string::npos){
    return "Automorphic";
  }
  else{
    return "Not!!";
  }
}
int main(){
    cout<<autoMorphic(225);
}