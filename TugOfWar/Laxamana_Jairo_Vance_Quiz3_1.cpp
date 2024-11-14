#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using std::chrono::system_clock;

int input;
int players;
int individual;

int team1[4];
int team2[4];
int sum1;
int sum2;

int digits_entered;

int main(){
    cout<<"Let's all play TUG OF WAR"<<endl;
    cout<<"Enter a 8 digit binary number."<<endl;
    cout<<"We then tally up everyone together and see who wins?"<<endl;

    // Getting Players
    cin>>input;
    players=input;
    
    // Input Validator
    while (input > 0){
        individual = input % 10;
        input = input / 10;
        digits_entered+=1;
        
        if (individual > 1){
            cout<<"Please only enter 1 or 0.";
            exit(0);
        }
        
        if (digits_entered==8){
            cout<<"Please enter only 8 digits";
            exit(0);
        }
    }
    // Assigns Teams
    cout<<"Assigning teams"<<endl;
    sleep_for(seconds(1));
    int i=0;
    while (players > 0){
        individual = players %10;
        players = players / 10;
        
        if (i<4){
            team1[i] = individual;
            cout<<team1[i]<<" Has joined team 1"<<endl;
            }
        if(i>=4){
            team2[i-4] = individual;
            cout<<team2[i-4]<<" Has joined team 2"<<endl;
            }
        i++;
        }
    
    cout<<"Tallying the scores"<<endl;
    sleep_for(seconds(1));

    // Tug of war
    for(i=0;i<4;i++){
        sum1= sum1 + team1[i];
        cout<<team1[i]<<" Added for team 1 "<<endl;
        sleep_for(milliseconds(250));
        sum2 = sum2 + team2[i];
        cout<<team2[i]<<" Added for team 2"<<endl;
        sleep_for(milliseconds(250));
    }
    
    cout<<"The scores are in...."<<endl;
    sleep_for(seconds(1));
    cout<<"Team 1 got "<< sum1<<endl;
    sleep_for(seconds(1));
    cout<<"Team 2 got "<< sum2<<endl;
    sleep_for(milliseconds(500));
    cout<<"The winner.....";
    sleep_for(seconds(2));

    if (sum1>sum2){
        cout<<"Team 1!!!!"<<endl;
    }
    else if (sum1==sum2){
        cout<<"BOTH, It's a tie!!!!!!"<<endl;
    }
    else{
        cout<<"Team 2!!!!"<<endl;
    }
    cout<<"Congratulations to the team that one but more importantly to every who participated."<<endl;
    cout<<"Have great afternoon everyone!!!";    
    return 0;
}