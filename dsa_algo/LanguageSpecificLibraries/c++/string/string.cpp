#include <iostream>
#include <string>


int main()
{
    //constructor
    std::string default_string;
    std::string default_string_ini("I am a string");
    std::string copy_string(default_string_ini);
    std::string range_string(default_string_ini, 0, 4);  //donor string, start and chars to copy
    std::string range_string_iterators(default_string_ini.begin(), default_string_ini.end());
    std::string fill_string(7, 'a');  //creates string of 7 a's
    //assign operator =, to assign value to string or change value
    fill_string = "hello there";
    
    //iterator begin() and end() 
    for(std::string::iterator it = fill_string.begin(); it != fill_string.end(); ++it)
        std::cout<<*it<<' ';
    std::cout<<'\n';

    //capacity functions
    //size() returns size of string in terms of bytes/number of chars
    //length() returns size of string in terms of bytes/number of chars
    //max_size() returns max number of chars string can possibly hold
    //resize()  resizes string to size n.
    //if current_size < n, resizes first characters to size n, and deletes rest
    //if cuurent_size > n, filler element are added to reach size n
    //extra parameter can be passed to use as filler element
    std::string str = "hello";
    str.resize(7, '!');  //increases size to 7 and uses ! as filler
    std::cout<<str<<'\n';
    //capacity() returns total number of elements string can currently hold
    //clear() deletes contents of string and resizes to 0
    //empty() returns boolean if string is empty
    //shrink_to_fit() resizes string to fit chars
    //[] returns reference to character at index. Can be used to access or modify contents at index
    str[6] = '?';
    std::cout<<str<<'\n';
    //at() returns reference to char at index if exists, or out of range exception if doesn't exist
    //back() returns reference to last char of string. Can be modified
    //front() return reference to first char of string. Can be modified
    //+= can be used to append a string or char to a string
    str.clear();
    str+= "hello";
    str+= '!';
    std::cout<<str<<'\n';
    //append() used to append to string
    str.clear();
    str.append("hi ");
    str.append(fill_string);  //append another string
    str.append(str, 9, 5);   //substring/range, takes donor, start index and # of chars to copy
    str.append("hi...", 2, 3);  //append substring starting at 2 and taking 3 chars
    //push_back() appends a single char at end of string
    str.clear();
    str.push_back('h');
    //pop_back() deletes last char of string
    //assign() replaces contents of string with new content
    str.assign(fill_string);
    str.assign(fill_string, 0, 5);  //range takes donor, start, number of chars
    str.assign("hello there", 5); // range takes first 5 chars and set string to it
    str.assign("I am assigning this string");
    //insert() insert before specified index
    str.clear();
    str = "hi";
    str.insert(2, "there");
    str.insert(2, "there...", 5, 3);  //insert before index 2, starting at index 5 take 3 chars from donor
    str.insert(2, 3, ':');   //fill insert 3 ':' before index 2
    str.insert(str.end(), 1, '!');  //fill insert '!' at end of string
    //erase() 
    //current string hi:::...there!
    str.erase(2, 3);  //start deleting at index 2 and delete 3 chars
    str.erase(10);  //erase single char at index
    str.erase(str.begin(), str.end());  //deletes range
    std::cout<<str<<'\n';
    //replace() 
    str.clear();
    str = "...hi";
    str.replace(3,2, "hello");  //start at index 3 replace next 2 chars with hello
    //current string ...hello
    //start at index 3, replace next 5 chars. from donor start at index 5 and take next 5 chars
    str.replace(3, 5, "I am there", 5, 5);  
    str.replace(0,3, 3, '!');  //replace first 3 chars with 3 copies of '!'
    //string operations
    //find() returns index of first match if found
    std::size_t found = str.find('t');
    if(found != std::string::npos)
        std::cout<<found<<'\n';
    found = str.find('e', 8);  //second parameter tells it to start search at index 8
    //rfind() returns last instance of sequence if found
    str = "I a, am six. I am six";
    found = str.rfind("six");
    if(found != std::string::npos)
        std::cout<<found<<'\n';
    //find_first_of() takes a sequence of chars, returns first instance any of chars in sequence are found
    found = str.find_first_of(".,"); //will return index of first occurrence of either , or .
    //find_last_of() takes sequence of chars, returns last instance of any of chars in sequence.
    found = str.find_last_of(".,");
    //find_first_not_of() takes sequence and returns first instance of any char not in input sequence
    found = str.find_first_not_of("a., ");
    //find_last_not_of() takes sequence and returns last instance of any char not in input sequence
    found = str.find_last_not_of(".,");
    //compare() compares string. returns 0 if they match, returns > 0 or < 0 if they don't match
    std::string str1 = "HI";
    std::string str2 = "HI";
    std::cout<<str1.compare(str2)<<'\n';
    std::cout<<found<<'\n';
    std::cout<<str<<'\n';
    //substr() 
    found =str.find_last_of('I');
    str1 = str.substr(found, 4);  //starts substring from index of I and takes 4 chars
    str2 = str.substr(str.find_last_of('s') ); //starts substring from s, since no second argument, it goes until end of string
    std::cout<<str1<<'\n';
    std::cout<<str2<<'\n';

    return 0;
}