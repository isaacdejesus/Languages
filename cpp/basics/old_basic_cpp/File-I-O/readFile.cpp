#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::string var;
    //declare stream object to read file
    std::ifstream readFile;
    //open file
    readFile.open("file.txt");
    //check if file is open
    //Method1: stores strings into string
    if(readFile.is_open())
    {
        //keep reading until end of file
        while(!readFile.eof())
            {
                readFile>>var;
                std::cout<<var<<'\n';
            }
    }
    readFile.close();

    //Method 2:to read the file. This one stores entire line into string
    std::string line;
    readFile.open("file.txt");
    while(!readFile.eof())
    {
        getline(readFile, line);
        std::cout<<line<<'\n';
    }
    readFile.close();

    //Method 3: store individual chars 
    char c;
    readFile.open("file.txt");
    while(readFile.get(c))
        std::cout<<c;
    if(readFile.eof())
        std::cout<<"reached end of file"<<'\n';
    readFile.close();

    //if a file has unwanted info such as info . info . info .
    //we can extract info but it only works if we know the format and format repeats
    std::string save;
    char trash;
    readFile.open("file2.txt");
    while(!readFile.eof())
    {
        readFile>>save>>trash;
        std::cout<<save<<" ";
    }

    readFile.close();
    return 0;
}