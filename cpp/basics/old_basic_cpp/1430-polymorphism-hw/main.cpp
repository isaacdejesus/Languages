#include "Phonebook.h"
int main()
{
   Phonebook myPhonebook(5);
   myPhonebook.readFromFile("input.txt");

   Phonebook copyof=myPhonebook;
   //copyof.addContact("B", "Business3 city3 random@mail.com 777-000-0000");
   //myPhonebook.deleteContact("777-777-7778");
   //myPhonebook.addContact("P", "Fname9 Lname3 01/01/01 pemail3@email.com 777-777-7778");
   myPhonebook.deleteContact("777-777-7779");
   myPhonebook.addContact("B", "Business2 City2 bemail2@mail.com 177-747-7779");

   myPhonebook.print();
   copyof.print();
   std::cout<<(copyof==myPhonebook);
   return 0;
}