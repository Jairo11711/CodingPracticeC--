#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string input;
    cout<<"String to evaluate: ";
    cin>>input;

    string longest_string;
    string current_longest;
    int value_to_find = 0;

    for (char& c : input){
        int ascii_value = int(tolower(c));

        //Check if next token is consecutive
        if (value_to_find==ascii_value){
            current_longest += c;
            value_to_find = ascii_value + 1;
            
            if(current_longest.size()>longest_string.size()){
                longest_string=current_longest;
            }
        }

        // Start
        else if (value_to_find==0){
            current_longest += c;
            value_to_find = ascii_value + 1;

            if(current_longest.size()>longest_string.size()){
                longest_string=current_longest;
            }
        }

        //restart token if not consecutive
        else{
            value_to_find = 0;
            current_longest = "";
        }
    }

    if (longest_string.size()>1){
        cout<<"Longest Consecutive Equal Substring Found: "<<longest_string;
    }  
    else{
        cout<<"404 Not Found";        
    }


    return 0;
}