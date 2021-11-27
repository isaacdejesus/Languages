#include<iostream>
typedef char gender;


void determineSex(char i)
{
    switch(i)
    {
        case 'd': 
                std::cout<<"Cool, I have a Dick too!!!";
                break;
        case 'p': 
                std::cout<<"May I interest you in having somethig nice and long inside?";
                break;
        default:
            std::cout<<"Idk what to tell you...";
    }
}
int main()
{
    gender personGender;
    std::cout<<"Please check what's under the hood and type: 'd' or 'p'"<<'\n';
    std::cin>>personGender;
    while(personGender!='p' && personGender!='d')
    {
        std::cout<<"Enter a valid choice: 'd' or 'p'"<<'\n';
        std::cin>>personGender;
    }
    determineSex(personGender);
    return 0;
}