#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

///////////////////////////////////////////////

                                         //STEPS

//1. getting input from the user to fill the 9x9 sudoku puzzle
//2. check wether the sudoku input is safe or not.
//3. numbers from 1-9 to be filled in the given boxes and the place unfilled is denoted by 0.
//4. now go in a row and check wether the box is empty or not. 
  //4.1 if the box is not empty move to the next box. if all the boxes are filled return true. 
  //4.2 in the non empty box, fill a number - then check if the number is present inside the 3x3 box, in the particular row or particular column. if          any of these satisfies then return false and check with the next number. if the correct number is found , then enter the number in the box and        return true.

//////////////////////////////////////////////////

					// DECLARATIONS

#define N 9
#define EMPTY 0

void get_sudoku(int play[][N]);
void print_sudoku(const int play[][N]);
bool solve_sudoku(int play[][N], int row, int column);
bool is_safe(int play[][N], int row, int column, int number);
bool is_row(int row[], int column, int number);
bool is_column(int play[][N], int row, int column, int number);
bool is_square(int play[][N], int row, int column, int number);
 
///////////////////////////////////////////////////

int main()
{

int play[N][N] = {{EMPTY}};

get_sudoku(play);

solve_sudoku(play, 0, 0);

print_sudoku(play);

return 0;


}


////////////////////////////////////////////////////

void get_sudoku(int play[][N]){


  for(int i=0; i<9; i++){

	for(int j=0; j<9; j++){

		cin >> play[i][j];

		//while(play[i][j] > 9 && play[i][j] < 1){

		//	cout << "please enter a logical value" << endl;
		//	cin >> play[i][j];

		//	}
		
		}

	}

}

////////////////////////////////////////////////////

void print_sudoku(const int play[][N]){


  for(int i=0; i<9; i++){

	for(int j=0; j<9; j++){

		cout << play[i][j] << " ";

		}
	
	cout<<"\n";

	}


}


////////////////////////////////////////////////////


bool solve_sudoku(int play[][N], int row, int column){


//.....defining the next rows and columns

int row_next, column_next;

 if(column == N-1){

	row_next = row + 1;

	}
 else{ 
 	row_next = row;

	}

 if(column == 8){

	column_next = 0;

	}else{
	
	column_next = column+1;

	}




//......if the place is not empty then the increment the position and try to fill the position

  if(play[row][column] != EMPTY){

	return solve_sudoku(play, row_next, column_next);

	}




//......if the row is incremented to 9 then that means that all the empty places have been filled and thus true is returned

  if(row == 9){

	return true;	

	}

  for(int number = 1; number <= N; number++){

	play[row][column] = number;
	
	if(is_safe(play, row, column, number) && solve_sudoku(play, row_next, column_next)) {

		  return true;

		}

	play[row][column] = EMPTY;

	}

  return false;


}


///////////////////////////////////////////////////////


bool is_safe(int play[][N], int row, int column, int number){

 return ((is_row(play[row], column, number) && is_column(play, row, column, number)) && is_square(play, row, column, number));



}

///////////////////////////////////////////////////


bool is_row(int row[], int column, int number){

 for(int i=0; i<N; i++){


	if((i != column) && (row[i] == number)){

		return false;
		
	
		}


	}

  return true;

}


///////////////////////////////////////////


bool is_column(int play[][N], int row, int column, int number){

 for(int i=0; i<N; i++){


	if((i != row) && (play[i][column] == number)){

		return false;
	
		}


	}

  return true;

}

//////////////////////////////////////////

bool is_square(int play[][N], int row, int column, int number){

 
int sq_row = (row/3)*3;
int sq_column = (column/3)*3;

for(int i = sq_row; i< (sq_row + 3); i++){

	for(int j = sq_column; j < (sq_column + 3); j++){


		if((i != row || j != column) &&  play[row][column] == number){

			return false;				
		
			}
		

		}

	}

 return true;

}

///////////////////////////////////////////////////////





                      //.............................................END..........................................//





