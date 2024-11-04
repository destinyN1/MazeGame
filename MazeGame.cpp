#include <iostream>// Standard c++ Libarary
#include <string.h>
#include <vector> // Vector Container
#include <random>

using namespace std;

// Variable declaration
int num_rows;
int num_columns;
int i;
int j;
vector<vector<string>> board; //2D Board that holds strings
//Main function
int main(){
    // Declaring GridGen function
    int GridGen();

    

    // Prompt user to input rows & columns
    cout << "Enter number of rows:" << endl;
    cin >> num_rows;
    cout << "Enter number of columns" << endl;
    cin >> num_columns;
    GridGen();
    return 0;
} 
int GridGen(){
int MazeMaker();
int RandomGen();
    //Loops through each row and adds the columns to it
    for (int i = 0; i < num_rows; i++){
        vector<string> row; // vector for storing rows and columns
     for (int j = 0; j < num_columns; j++){

     
        if (j == 0)
         row.push_back("|_|"); //If on the first element of row vector 
        else
        row.push_back ("_|"); // If on any other element
    }
    board.push_back(row); // Add new row vector onto the Board
    }
    //Prints the board
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_columns; j++){
            cout << board[i][j];
        }
           cout << "\n"; //Print next line of board
    }
    //If grid area bigger than 8 then generate a random number
    if ((num_columns*num_rows>=9)){
     RandomGen();

   }
   else 
   return 0;
}
//Funtion to generate another maze (might be used later)
int Mazemaker(){
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_columns; j++){
            cout << board[i][j];
        }
           cout << "\n"; //Print next line of board
    }
    
    return 0;
}

int RandomGen (){
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<>distr(0, (num_columns*num_rows));
   for (int n = 0; n<1; n++){
    cout<<  "random number: "<< distr(gen) << endl;
   }
return 0;
}