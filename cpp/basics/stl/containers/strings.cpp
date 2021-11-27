#include <iostream>
#include "functions.h"
//compile g++-std=c++2a strings.cpp functions.cpp -o S
int main()
{
    std::string a_string;
    a_string = "An ode to the great potato man. Once there was a potato man. He was so great...";
    print_ln(a_string);

    //constructors
    //default
    std::string default_constructor ("Ah, yes, the original great potato man");
    //copy
    std::string copy_constructor (default_constructor);
    print_ln(copy_constructor);
    //substring arguments = source string, starting point, how many chars to copy
    std::string sub_string_constructor (default_constructor, 0, 7);
    print_ln(sub_string_constructor);
    //can use begin() end() iterators like on vectors
    //can also use size() and length() functions to return size of string
    //Can also use clear() to delete contents of string
    //can also use empty() to check if string is empty
    //characters can be accessed using: at(), [], front(), back()
    
    //string operations
    //find returns locations of first occurrence of char or substring
    std::cout<<a_string.find("potato")<<'\n';
    std::cout<<a_string.find('.')<<'\n';
    //rfind returns location of last occurrence of a sequence or char
    std::cout<<a_string.rfind("potato")<<'\n';   
    //create substrings takes in as arguments the initial location and number of chars to copy`
    std::string a_sub_string = a_string.substr(49,6);
    print_ln(a_sub_string);
    //compare returns 0 if al chars in a string match
    if(default_constructor.compare(copy_constructor) == 0)
        print_ln("they match");
    //modifiers
    //replace
    //take the initial location, # chars to replace and what to replace it with
    //replacement could be a string of chars or another var containing a string
    std::string a_new_string = "Ah, yes, the original great potato man";
    std::string another_string = "Sometimes, he can be godly";
    int great_location = a_new_string.find("great");
    int godly_location = another_string.find("godly");
    a_new_string.replace(great_location, 5, "amazing");
    print_ln(a_new_string);
    //takes in original's string initial location to the replaced and # of chars to be replaced
    //followed by source of replacement, initial location and number of chars to take from 
    a_new_string.replace(great_location, 7, another_string, godly_location, 5);
    print_ln(a_new_string);

    //+= and  append()  can append to strings can append to strings.
    //push_back() can only add one char to string
    //pop_back() will delete last char in string
    std::string add_to_me;
    add_to_me=+("I am the great");
    add_to_me.push_back(' ');
    add_to_me.append("potato man!");
    print_ln(add_to_me);

    //there is also an insert modifier...
    //insert
    std::string a_new_string1 = "i am the potato man";
    std::string amazing = "the amazing ";
    //takes in location and string or var to insert
    a_new_string1.insert(9, "great ");
    print_ln(a_new_string1);
    //take substring from amazing starting from 4th char and next 6
    //then insert into string at location 9th char
    a_new_string1.insert(9, amazing, 4, 6);
    print_ln(a_new_string1);
    //takes starting location and string inserts starting from 0, and however many chars want to add
    a_new_string1.insert(9,"super godly potato boi ", 11);
    print_ln(a_new_string1);
    a_new_string1.insert(9, "something ");
    print_ln(a_new_string1);
    //inserts 5 copies of ':' at location 9
    a_new_string1.insert(9, 5, ':');
    print_ln(a_new_string1);
    return 0;
};
