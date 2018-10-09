// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
/* programmers: Ahmed Sayed Mansour   20170022
                Eslam Saleh Mohamed   20170046
                Eslam Mohamed Mahmoud 20170049
*/
// last edit : 6/10/2018
// Version: 1.1

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
ostream& operator<< (ostream& out, matrix mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose  (matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{

    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3, mat4, mat_temp_1, mat_temp_2, mat_temp_3;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
    createMatrix (2, 4, data4, mat4);

    createMatrix (4, 2, data1, mat_temp_1);
    createMatrix (2, 3, data2, mat_temp_2);
    createMatrix (4, 2, data3, mat_temp_3);


// The next code will not work until you write the functions

    cout << "mat1 : " << endl;
    cout << mat1 << endl;

    cout << "mat2 : " << endl;
    cout << mat2 << endl;

    cout << "mat3 : " << endl;
    cout << mat3 << endl;

    cout << "mat4 : " << endl;
    cout << mat4 << endl;

    cout << "mat1 + mat3 : " << endl;
    cout << (mat1 + mat3) << endl << endl;

    cout << "mat3 + mat3 : " << endl;
    cout << (mat3 + mat3) << endl << endl;

    cout << "mat3 - mat1 : " << endl;
    cout << (mat3 - mat1) << endl << endl;

    cout << "mat1 * mat2 : " << endl;
    cout << (mat1 * mat2) << endl << endl;

    cout << "mat1 + 3 : " << endl;
    cout << (mat1 + 3) << endl << endl;

    cout << "mat1 - 3 : " << endl;
    cout << (mat1 - 3) << endl << endl;

    cout << "mat1 * 3 : " << endl;
    cout << (mat1 * 3) << endl << endl;

    ++mat1;
    cout << "++mat1 : " << endl;
    cout << mat1 << endl;

    --mat1;
    cout << "--mat1 : " << endl;
    cout << mat1 << endl;

    mat1+=mat3;
    cout << "after  mat1 += mat3 : " << endl;
    cout << "mat1 : " << endl;
    cout << mat1 << endl;

    cout << "mat2 : " << endl;
    cout << mat2 << endl;

    cout << "mat3 : " << endl;
    cout << mat3 << endl;

    mat1-=mat3;

    cout << "after  mat1-=mat3 : " << endl;
    cout << "mat1 : " << endl;
    cout << mat1 << endl;

    cout << "mat2 : " << endl;
    cout << mat2 << endl;

    cout << "mat3 : " << endl;
    cout << mat3 << endl;

    cout << "mat1 += 3 : " << endl;
    cout << (mat1 += 3) << endl << endl;

    cout << "mat1 -= 3 : " << endl;
    cout << (mat1 -= 3) << endl << endl;

    matrix matt;
    cout << "Enter H * W and Matrix : ";
    cin>>matt;

    cout <<"Your  "<<matt.row<<" * "<<matt.col<<"  matrix is "<< endl;
    cout << matt << endl << endl;

    cout << "mat1 == mat1 : " << endl;
    cout << (mat1 == mat1) << endl << endl;

    cout << "mat1 != mat3 : " << endl;
    cout << (mat1 != mat3) << endl << endl;

    matrix myMat;

    cout<<"Enter H * W && Matrix to check if Square : " << endl;
    cin>>myMat;
    cout << "isSquare(myMat) : ";
    cout <<  isSquare(myMat) << endl << endl;

    cout<<"Enter H * W && Matrix to check if Symetric : " << endl;
    cin>>myMat;
    cout << "isSymetric(myMat) : ";
    cout <<  isSymetric(myMat) << endl << endl;

    cout<<"Enter H * W && Matrix to check if Identity : " << endl;
    cin>>myMat;
    cout << "isIdentity(myMat) : ";
    cout <<  isIdentity(myMat) << endl << endl;

    cout<<"Enter H * W && Matrix to Iranspose : " << endl;
    cin>>myMat;
    cout << "transpose(myMat) : " << endl;
    cout <<  transpose(myMat) << endl << endl;





    // Add more examples of using matrix
    // .......



    //Free each sub-array

    for(int i=0;i<4;++i){
        delete [] mat1.data[i];
        delete [] mat3.data[i];
        delete [] mat_temp_1.data[i];
        delete [] mat_temp_3.data[i];
    }
    for(int i=0;i<2;++i){
        delete [] mat2.data[i];
        delete [] mat4.data[i];
        delete [] mat_temp_2.data[i];
    }

    //free each array of pointers

    delete [] mat1.data;
    delete [] mat3.data;
    delete [] mat_temp_1.data;
    delete [] mat_temp_3.data;
    delete [] mat2.data;
    delete [] mat4.data;
    delete [] mat_temp_2.data;


    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}

//Input Function

ostream& operator<< (ostream& out, matrix mat)
{
    for (int i = 0; i < mat.row; i++)
    {
        out<<endl;
        for (int j = 0; j < mat.col; j++)
            out << mat.data[i][j]<<"  ";
    }
    out<<endl<<endl;

    return out;
}

// A function to set rows and cols
void setRowAndCol(matrix& mat,int row,int col)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int*[row];
    for (int i = 0; i < row; i++)
        mat.data[i] = new int[col];
}


/// Student 1

// A function to get the sum of two matrices

matrix operator+(matrix mat1, matrix mat2)
{

    assert((mat1.row == mat2.row) && (mat1.col == mat2.col)); //to sure if rows and cols are equal
    matrix mat;
    setRowAndCol(mat, mat1.row, mat2.col);        //setting number of rows and cols in object mat

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat2.col; j++)
            mat.data[i][j] =0;                // initialize all values equal 0

    for(int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] =(mat1.data[i][j] + mat2.data[i][j]);    //get the sum(all values mat1+ all values in mat2) and put it in mat
        }
    }
    return mat;
}

// A function to remove the value of another matrix from it

matrix operator-(matrix mat1, matrix mat2)
{

    assert((mat1.row == mat2.row) && (mat1.col == mat2.col));   //to sure if rows and cols are equal
    matrix mat;
    setRowAndCol(mat, mat1.row, mat2.col);

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat2.col; j++)
            mat.data[i][j] =0;                 //initialize all values to 0


    for(int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] =(mat1.data[i][j] - mat2.data[i][j]);    //remove values
        }
    }
    return mat;
}

//  A function to produce two matrices

matrix operator*(matrix mat1, matrix mat2)
{
    assert((mat1.col == mat2.row));        //to sure if rows and cols are equal
    matrix mat;
    setRowAndCol(mat, mat1.row, mat2.col);

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat2.col; j++)
            mat.data[i][j] =0;         // initialize all values to 0

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat2.col; j++)
            for ( int k = 0; k < mat1.col; k++ )
            {
                mat.data[i][j] += mat1.data[i][k] * mat2.data[k][j];   //get the production
            }
    return mat;
}

// A function to add a value to A matrix

matrix operator+(matrix mat1, int scalar)
{

    matrix mat;
    setRowAndCol(mat, mat1.row,mat1.col);

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat1.col; j++)
            mat.data[i][j] =0;    //initialize all values to 0


    for(int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] =(mat1.data[i][j] + scalar);   //get the sum
        }
    }
    return mat;
}

//A matrix to remove a value from a matrix

matrix operator-(matrix mat1, int scalar)
{

    matrix mat;
    setRowAndCol(mat, mat1.row,mat1.col);

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat1.col; j++)
            mat.data[i][j] =0;          //initialize all values to 0


    for(int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] =(mat1.data[i][j] - scalar);  //the equation
        }
    }
    return mat;
}

// A function to produce a value in  a matrix

matrix operator*(matrix mat1, int scalar)
{

    matrix mat;
    setRowAndCol(mat, mat1.row,mat1.col);

    for(int i = 0; i < mat1.row; i++)
        for ( int j = 0; j < mat1.col; j++)
            mat.data[i][j] =0;            //initialize all values to 0


    for(int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] =(mat1.data[i][j] * scalar);    //The equation
        }
    }
    return mat;
}


/// Student 2


// Increment Matrix Elements By 1

void  operator++ (matrix& mat)
{
    for(int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j]++; // loop then increase every element by one
}

// Decrement Matrix Elements By 1

void  operator-- (matrix& mat)
{
    for(int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j]--; // loop then decrease every element by one
}

// Append Second Matrix Elements to the First One

matrix operator+= (matrix& mat1, matrix mat2)
{
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col)); //Check if 2 matrices have same dimensions

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat1.data[i][j] += mat2.data[i][j]; // loop and add second matrix element to the first one

    return mat1;
}

// Substract Second Matrix Elements from the First One

matrix operator-= (matrix& mat1, matrix mat2)
{
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col)); //Check if 2 matrices have same dimensions

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat1.data[i][j] -= mat2.data[i][j]; // loop and remove second matrix element to the first one

    return mat1;
}

//Increase Matrix Elements with Given Constant Value

matrix operator+= (matrix& mat1, int scalar)
{
    matrix mat;
    setRowAndCol(mat, mat1.row, mat1.col);

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat.data[i][j]=mat1.data[i][j]; // Make a temp matrix not to change values of the main matrix

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat.data[i][j] += scalar; // add the constant value to the temp matrix

    return mat;
}

//Decrease Matrix Elements by Given Constant Value

matrix operator-= (matrix& mat1, int scalar)
{
    matrix mat;
    setRowAndCol(mat, mat1.row, mat1.col);

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat.data[i][j]=mat1.data[i][j]; // Make a temp matrix not to change values of the main matrix

    for(int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat.data[i][j] -= scalar; // remove the constant value to the temp matrix

    return mat;
}

//Input Function

istream& operator>> (istream& in, matrix& mat)
{
    cin>>mat.row>>mat.col;  // Take rows and cols from the user

    mat.data = new int* [mat.row];

    for (int i = 0; i < mat.row; i++)
        mat.data[i] = new int [mat.col];

    for(int i=0; i<mat.row; i++)
        for(int j=0; j<mat.col; j++)
            in>>mat.data[i][j]; // Enter Elements Gradually

    return in;
}


/// Student 3

//check if two matrices are equal and return 1 if equal and 0 if not

bool operator== (matrix mat1, matrix mat2)
{
    if( (mat1.row != mat2.row) || (mat1.col != mat2.col) )    // the same as assert
    {
        return false;
    }
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i][j]!=mat2.data[i][j])
                return false;
        }
    }
    return true;
}

//check if two matrices are equal and return 0 if equal and 1 if not

bool operator!= (matrix mat1, matrix mat2)
{
    if( (mat1.row != mat2.row) || (mat1.col != mat2.col) )
    {
        return true;
    }
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i][j]!=mat2.data[i][j])
                return true;
        }
    }
    return false;
}

// check if number of rows equal the number of cols and return 1 if equal and return 0 if not

bool isSquare(matrix mat)
{
    if( mat.row == mat.col )
        return true;
    else
        return false;
}

// check if the value of matrix [i][j] equal the value matrix [j][i] and return 1 if equal and return 0 if not

bool isSymetric(matrix mat)
{
    if( (isSquare(mat))==false )
        return false;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            if( mat.data[i][j] != mat.data[j][i] )  //check if they are equal
                return false;
        }
    }
    return true;
}

// check if all values of the main diagonal equal 1's and return 1 if equal and return 0 if not

bool isIdentity(matrix mat)
{
    if( isSquare(mat)==false )
        return false;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            if( i==j )
            {
                if( mat.data[i][j] != 1 )    // check if all main diagonal values are equal to one
                    return false;
            }
            else if( mat.data[i][j] != 0 )
                return false;
        }
    }
    return true;
}

// A function to rotate a matrix;

matrix transpose(matrix mat1)
{
    matrix mat;
    setRowAndCol(mat, mat1.col, mat1.row);

    for(int i = 0; i < mat.row; i++)
        for ( int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat1.data[j][i];     //put all values in the rotated matrix

    return mat;
}
