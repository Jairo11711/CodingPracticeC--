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

    int highest_value = *max_element(barChart_values.begin(), barChart_values.end());
    const int  horizontal_spacing = 3; // 2 for right box side, 2 for the left box side
    const int vertical_spacing = 4; //3+2 3 cuz 1 space for the bottom, 2 for the top
                                    //and +2 cuz 2 rows lines was being eaten for printing
    

    clms = horizontal_spacing + bar_amount;
    rows = vertical_spacing + highest_value - 1;

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
            // Also code for the barchart is here
            if (i!=0 && i!=rows-1){

                if (i==1&&j!=clms-1){
                    cout<<"  ";
                }  

                // Handles printing the bars
                else if(j>0 && j<clms-2){
                    int data = barChart_values[j-1];
                    int top_spacing = *max_element(barChart_values.begin(), barChart_values.end()) - data;
                    int translated_i = i-2;
                    if(translated_i>top_spacing-1){
                        cout<<" #"; 
                    }
                    else{
                        cout<<"  ";
                    }

                }
                else if (j==clms-1){
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