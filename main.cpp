#include <iostream>
#include <iomanip> //allows me to use setw
using namespace std;

void charCheck(char &check);
void MagicSquare(int &order, int square[10000][10000]);

int main()
{
    //Declare new variables to allocate new memory every time user wants to continue program
	int *num = new int;
	char *cont = new char;
	cout << "Welcome to my Odd Order Magic Square Program!" << endl;
//Start of do while loop
	do{
    cout << "Enter the order of square: ";
    cin >> *num;
    int square[10000][10000] = {};      //set dimensions of square to a high number. Set value of position equal to 0

    if (*num % 2 != 0)                  //If entered number is odd
        {
            cout << "Magic Square of order: " << *num;
            MagicSquare(*num, square);          //call magic square function
        }
    else                             //if not odd
        cout << "Invalid input: Order must be an odd integer" << endl; //tell user the input must be odd and integer

    cout << endl;  //for readability

    cout << "Continue? (y or n)" << endl;
    cin >> *cont;
    charCheck(*cont);            //check if user entered y or n correctly to continue loop

	}
	while (*cont == 'y' || *cont == 'Y');       //loop continues while user keeps entering y
    return 0;                  //end of main function
}


void charCheck(char &check)       //program that checks if user enters correct character
{
    if (check == 'y' || check == 'Y')
    {
        cout << "";
    }
    else if (check == 'n' || check == 'N')
    {
        cout << "Closing program..." << endl;
    }
    else
    {
        cout << "Invalid input! Closing program..." << endl;
    }
}
void MagicSquare(int &order, int square[10000][10000]) //magicsquare function that determines values for each cell
{
        int row = 1 ;                       //row starts on row 1
		int col = (order) / 2;        //col starts at middle
		int maxn = (order) * (order);   //max number of values

		for (int k = 1; k <= maxn; k++)          // starts at (1,2)
        {
            if (square[row][col] || ((row == 0) && col == order))
			{
				row = row + 2; //go down 2 rows
				col = col - 1; //go to the left 1 col
			}
            else if (row == 0) //if row is in the outer top row
                    row = order;  //set row to the last row

            else if (col == order) //if col is on outer right col which is all the way to the right
                    col = 0;      //set col to 0 which is all the way to the left
            else
                cout << "";
            square[row][col] = k;   //set position to k

            row--;         //row - 1
            col++;         //col + 1
        }

        cout << endl;
        for (int row = 1; row <= order; row++) //this for loop sets the matrix
        {
            for (int col = 0; col < order; col++)
                {
                cout << setw(5) << square[row][col] << setw(5); //setw spaces out the numbers
                }
            cout << endl;
        }
        int sum = order * (order * order + 1) / 2;  //gives sum
        cout << "Sum of each row, column, and diagonal in Magic Square is " << sum << endl;
}
