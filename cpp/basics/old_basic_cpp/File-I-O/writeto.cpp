#include <iostream>
#include <fstream>
#include <string>

int main()
{
    //create output stream object
    //std::ofstream writeTo;
    //opens file but doesn't check if the file is open or exists
    //writeTo.open("file.txt");
    std::ofstream writeTo("file.txt");
    //checking to see if file is open
    if(writeTo.is_open())
    {

    writeTo<<" This is how you write to file"<<'\n';
    writeTo.close();

    //Other ways to open and write to file are:
    //open(filename, mode)
    //where mode= in/out/binary/ate/app/trunc
    //for example app allows us to append to the end of file
    writeTo.open("file.txt", std::ios_base::app);
    writeTo<<"Sometimes chicken potato soup is good for you"<<'\n';

    //sometimes, there is the need to flush the the buffer to write to file
    writeTo.flush();
    writeTo.close();
    }

    else 
        std::cout<<"Unable to open file";
    return 0;
}