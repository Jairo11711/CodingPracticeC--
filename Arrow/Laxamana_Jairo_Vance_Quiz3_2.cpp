#include <iostream>

int main()
{
// Input Hnadling
    // amount where every other number is converted to/
    int base;
    // the grid size
    int row_amount;
    int col_amount;
    // steppers in creating the triangle
    int downer;
    int upper;


    // Init the data
    std::cout << "Enter a number greater than 1 :";
    std::cin>>base;
    
    if(base <= 1){
        std::cout<<"Pleae only input numbers greater than 1.";
        return 0;
    }

    downer = base - 1;
    upper = 0;
    col_amount = (base * 2) + base;
    if (base%2 == 0){
        row_amount = (base * 2) - 1;}
    else{
        row_amount = (base * 2);}

// Main Logic

    // Builds the grid
    for (int i = 0; i < row_amount; i++) {
        for (int j = 0; j < col_amount; j++){
            
            //Creates the triangle body
            if (j < base){
                
                //Create top
                if (i <= base - 1){ 
                    if (i >= downer) {
                        std::cout << "*";}
                    else{
                        std::cout << " ";}
                }
                //Create bottom
                if (i > base - 1){
                    if (i-base < upper) {
                        std::cout << "*";}
                    else{
                        std::cout << " ";}
                }
            //step every col
            upper += 1;
            downer -= 1;   
            }
        }
        //Create Arrow Body

        // Is the amount of spacers the arrow needs on both sides.
        int space_amount_even = (((row_amount)-(base-1)) / 2);
        int space_amount_odd = (((row_amount)-(base)) / 2);

        //Handles even numbers
        if (base%2 == 0){ 
            if (i> space_amount_even-1) {
                if (i< (row_amount-space_amount_even) ){
                    for (int k=0;k<2*base;k++){
                        std::cout<<"*";
                    }
                }
            }   
        }
        //Handles odd numbers
        else{
            if (i> space_amount_odd-1) {
                if (i< (row_amount-space_amount_odd-1) ){
                    for (int k=0;k<2*base;k++){
                        std::cout<<"*";
                    }
                }
            }
        }
        //restart every row
        downer = base - 1;
        upper = 0;
        std::cout << std::endl;
    }

    return 0;
}