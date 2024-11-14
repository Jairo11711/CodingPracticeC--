#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> tokenizer(string s)
{
    vector<int> tokens;

    stringstream ss(s);
    string word;

    while (ss >> word) {
        tokens.push_back(stoi(word));
    }
    return tokens;
}

int main()
{
    int bar_amount;
    cout<<"Enter number of BarChart Values: ";
    cin>>bar_amount;
    vector<int> barChart_values;
    cout<<endl;
    cin.ignore();

    string bar_values;
    cout<<"Enter BarChart Values: ";
    getline (cin, bar_values);
    cout<<endl;

    barChart_values = tokenizer(bar_values);
    
    //Checks if values_amount match values given.
    if (barChart_values.size() != bar_amount){
        cout<<"Looks like you given etheir too much or too little values."<<endl;
        cout<<"Please match the amount of the given BarChart Values."<<endl;
        cout<<"Terminating program."<<endl;
        exit(0);
    }

    //Main Printing
    int clms;
    int rows;

    const int  horizontal_spacing = 4;
    const int vertical_spacing = 3;

    rows = horizontal_spacing + bar_amount;
    clms = vertical_spacing + *max_element(barChart_values.begin(), barChart_values.end()) - 1;

    for (int i=0;i<rows;i++){
        for (int j=0;j<clms;j++){



            // top of the box
            if (i==0){
            cout<<" 0";
            }
            // left of the box
            if (j==0){
            cout<<" 0";
            }
            // bottom of the box
            if (i==rows-1 ){
            cout<<" 0";
            }
            
            //right of the box
            if (i!=0 && i!=rows-1){
                if (j==clms-1){
                    cout<<" 0";
                }
                else{
                    cout<<"  ";
                }
            }



        }
        cout<<endl;
    }
    
    return 0;
}