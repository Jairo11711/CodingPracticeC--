#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> values = {4,5};
    int value = 4;
    int size = 5;
    

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){


            if(i>size-values[j]-1){
                cout<<" #";
            }
            else{
            cout<<" 0";
            }
        }
        cout<<endl;
    }

    return 0; 
}