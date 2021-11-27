#include <iostream>

void menu();
void selector(int val);
void operation( int op);
void addition(int **matrix1, int **matrix2, int **matrix3, int rows, int columns);
void substraction(int **matrix1, int **matrix2, int **matrix3, int rows, int columns);
void populatingarray(int **matrix1, int **matrix2, int rows, int columns);
void freeUpMem();
void printArray(int **arr, int rows, int columns);
void gatherValues(int &rows, int &columns);
int main()
{
    menu();
    return 0;
}

void menu() 
{
    int operation=0;
    do{
        std::cout<<"Select operation to perform: "<<'\n';
        std::cout<<"1) Matrix addition"<<'\n';
        std::cout<<"2) Matrix substraction"<<'\n';
        std::cout<<"3) Exit"<<'\n';
        std::cin>>operation;
           
        selector(operation);

    }
    while(operation!=3);
    std::cout<<"Adios mothafuckers"<<'\n';

}

void selector(int val)
{
    switch (val)
    {
    case 1:
        operation(1);
        break;
    case 2: 
        operation(-1);
        break;
    
    default:
        break;
    }
}

void operation(int op)
{
    //declare pointers to matrices
    int **matrix1;
    int **matrix2;
    int **matrix3;

    int rows;
    int columns;
    gatherValues(rows,columns);

    //set up dynamic 2d matrix1
    matrix1= new int*[rows];
    for(int i=0; i<rows; i++)
        matrix1[i]=new int[columns];

    //set up dynamic 2d matrix2
    matrix2= new int*[rows];
    for(int i=0; i<rows; i++)
        matrix2[i]=new int[columns];
    
    //set up dynamic 2d matrix3
    matrix3=new int*[rows];
        for(int i=0; i<rows; i++)
            matrix3[i]=new int[columns];

    populatingarray(matrix1, matrix2, rows, columns);

    if(op==1)
        addition(matrix1, matrix2, matrix3, rows, columns);
    else if (op==-1)
    {
        substraction(matrix1, matrix2, matrix3, rows, columns);
    }
    printArray(matrix3, rows, columns);

}

void populatingarray(int **matrix1, int **matrix2, int rows, int columns)
{

    int temp;
    std::cout<<"Enter "<<rows*columns<<" values to store in the first array: "<<'\n';
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            {
                std::cin>>temp;
                matrix1[i][j]=temp;
            }

    std::cout<<"Enter "<<rows*columns<<" values to store in the second array: "<<'\n';
    for( int i=0; i<rows; i++)
        for( int j=0; j<columns; j++)
            {
                std::cin>>temp;
                matrix2[i][j]=temp;
            }
}

void printArray(int **arr, int rows, int columns)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

void gatherValues(int &rows, int &columns)
{
    std::cout<<"Enter dimensions of the matrix: "<<'\n';
    std::cout<<"Enter number of rows: ";
    std::cin>>rows;
    std::cout<<'\n';
    std::cout<<"Enter number of columns: ";
    std::cin>>columns;
    std::cout<<'\n';
}

void addition(int **matrix1, int **matrix2, int **matrix3, int rows, int columns)
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            matrix3[i][j]=matrix1[i][j]+ matrix2[i][j];
}

void substraction(int **matrix1, int **matrix2, int **matrix3, int rows, int columns)
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            matrix3[i][j]=matrix1[i][j]- matrix2[i][j];
}
// void freeUpMem()
// {
//     for(int i=0; i<rows; i++)
//     {
//         delete [] array1[i];
//         delete [] array2[i];
//         delete [] array3[i];
//     }

//     delete [] array1;
//     delete [] array2;
//     delete [] array3;
// }
