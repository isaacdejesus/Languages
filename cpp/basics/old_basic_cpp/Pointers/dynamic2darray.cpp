#include <iostream>

void initializeTable(int **table, int *rowSize, int *colSize);
void fillTable( int **table, int *rowSize, int *colSize);
void displayTable(int **table, int *rowSize, int *colSize);
int main()
{
    //declare double pointer for table/matrix
    int **table= nullptr;
    int *tableRow=new int;
    int *tableCol=new int;

    //input
    std::cout<<"Enter number of rows"<<'\n';
    std::cin>>*tableRow;
    std::cout<<'\n';
    std::cout<<"Enter number of cols"<<'\n';
    std::cin>>*tableCol;
    std::cout<<'\n';

    //create rows
    table= new int *[*tableRow];
    
    for(int row=0; row< *tableRow; row++)
        {
            table[row]=new int[*tableCol];
        }
    
    //ini table
    initializeTable(table, tableRow, tableCol);
    fillTable(table, tableRow, tableCol);
    displayTable(table, tableRow, tableCol);
    return 0;
}

void initializeTable(int **table, int *rowSize, int *colSize)
{
    for( int row=0; row<*rowSize; row++ )
        {
            for( int col=0; col< *colSize; col++)
                {
                    table[row][col]=0;
                }
        }
}

void displayTable(int **table, int *rowSize, int *colSize)
{
    for( int row=0; row<*rowSize; row++ )
        {
            for( int col=0; col< *colSize; col++)
                {
                    std::cout<<table[row][col];
                }
            std::cout<<'\n';
        }
}

void fillTable(int **table, int *rowSize, int *colSize)
{
    int totalVal= (*rowSize)*(*colSize);
    std::cout<<"Enter "<<totalVal<<" values to store in the table: "<<'\n';
    for( int row=0; row<*rowSize; row++ )
        {
            for( int col=0; col< *colSize; col++)
                {
                    std::cin>>table[row][col];
                }
        }
}