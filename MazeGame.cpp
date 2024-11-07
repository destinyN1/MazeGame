#include <iostream> // Standard C++ Library
#include <string.h>
#include <vector> // Vector Container
#include <random>
#include <array>

using namespace std;

// Variable declaration
int num_rows;
int num_columns;
int i;
int j;
int input;
int RandomSize();
int SLCTSize();
int GridGen();
int Mazemaker();
int RandomNumGen();
vector<vector<string>> add_frontier();
//vector<vector<string>> frontier();
vector<vector<string>> local_frontier;
vector<vector<string>> board; // 2D Board that holds strings

// Main function
int main() {
    // Declaring GridGen function
    cout << "Do u want to make your own grid \n Press 1 for YES \n 2 for NO" << endl;
    cin >> input;

    if (input == 1) {
        SLCTSize();
    } else if (input == 2) {
        RandomSize();
    } else {
        cout << "Please enter either 1 or 2:" << endl;
    }

    return 0;
}

int RandomSize() {
    // Placeholders for grid sizes
    int value[2];
    random_device rc;
    mt19937 gen(rc());
    uniform_int_distribution<> distr(0, 30); // Max size computer can make the grid

    for (int n = 0; n <= 1; n++) {
        value[n] = distr(gen);
        //cout << value[n] << "\n";
        num_rows = value[0];
        num_columns = value[1];

    }

GridGen();
    return 0;
}

int SLCTSize() {
    // Prompt user to input rows & columns
    cout << "Enter number of rows:" << endl;
    cin >> num_rows;
    cout << "Enter number of columns:" << endl;
    cin >> num_columns;
    GridGen();
    return 0;
}

int GridGen() {
    // Loops through each row and adds the columns to it
    for (int i = 0; i < num_rows; i++) {
        vector<string> row; // Vector for storing rows and columns
        for (int j = 0; j < num_columns; j++) {
            if (j == 0)
                row.push_back("|_|"); // If on the first element of row vector
            else
                row.push_back("_|"); // If on any other element
        }
        board.push_back(row); // Add new row vector onto the Board
    }

    // Prints the board
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            cout << board[i][j];
        }
        cout << "\n"; // Print next line of board
    }
    //Dimentions of randomly generated grid
    cout << "Rows: "<< num_rows << endl; 
    cout << "Columns: " << num_columns << endl;

    // If grid area bigger than 8, then generate a random number
    if ((num_columns * num_rows >= 9)) {
        RandomNumGen();
    }

    return 0;
}


int RandomNumGen() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> row_distr(0, (num_rows -1));
    uniform_int_distribution<> column_distr(0, (num_columns - 1));
    
    //selects position coordinates of the board
    cout  << row_distr(gen);
    cout << column_distr(gen);

    return 0;
}

 vector<vector<string>> add_frontier( int i,int j, const vector<vector<string>>board, vector<vector<string>>local_frontier){ //frontier with reference to 2d board
    vector<vector<string>> local_frontier(num_rows, vector<string>(num_columns)); 

      local_frontier[i][j] = board[i][j];
       for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            cout << local_frontier[i][j];
        }
        cout << "\n";
    }
    return local_frontier;
}
 
 