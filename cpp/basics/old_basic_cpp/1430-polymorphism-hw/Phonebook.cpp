#include "Phonebook.h"
#include <sstream>
#include <fstream>
Phonebook::Phonebook(const int _size) : size(_size), numContacts(0)
{
    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
}

Phonebook::Phonebook(const Phonebook &origOBJ) : size(origOBJ.size), numContacts(origOBJ.numContacts)
{

    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (origOBJ.contacts[i] != nullptr)
        {
            if (origOBJ.contacts[i]->getType() == "B")
            {
                BusinessContact temp = *((BusinessContact *)origOBJ.contacts[i]);
                contacts[i] = new BusinessContact;
                *((BusinessContact *)contacts[i]) = temp;
            }
            else
            {
                PersonalContact temp = *((PersonalContact *)origOBJ.contacts[i]);
                contacts[i] = new PersonalContact;
                *((PersonalContact *)contacts[i]) = temp;
            }
        }
    }
}

const Phonebook &Phonebook::operator=(const Phonebook &ObjToCopy)
{
    if (this != &ObjToCopy)
    {
        for (int i = 0; i < size; i++)
        {
            if (contacts[i] != nullptr)
            {
                delete contacts[i];
                contacts[i] = nullptr;
            }
        }
        delete[] contacts;
        contacts = nullptr;
        size = ObjToCopy.size;
        numContacts = ObjToCopy.numContacts;
        contacts = new GenericContact *[size];
        for (int i = 0; i < size; i++)
            contacts[i] = nullptr;
        for (int i = 0; i < size; i++)
        {
            if (ObjToCopy.contacts[i] != nullptr)
            {
                if (ObjToCopy.contacts[i]->getType() == "B")
                {
                    BusinessContact temp = *((BusinessContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new BusinessContact;
                    *((BusinessContact *)contacts[i]) = temp;
                }
                else
                {
                    PersonalContact temp = *((PersonalContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new PersonalContact;
                    *((PersonalContact *)contacts[i]) = temp;
                }
            }
        }
    }
    return *this;
}

int Phonebook::findAvailablePosition()
{
    for(int i=0; i<size; i++)
        {
            if(contacts[i]==nullptr)
            {
                return i;
                break;
            }
        }
    return -1;
}

int Phonebook::findContactPosition(const string &_phoneNumber)
{
    for(int i=0; i<size; i++)
        {
            if(contacts[i]->getPhoneNumber()==_phoneNumber)
                {
                    return i;
                    break;
                }
        }
    return -1;
}

bool Phonebook::addContact(const string &type, const string &contactInformation)
{
    int insertAtIndex=findAvailablePosition();
    stringstream word(contactInformation);
    if(insertAtIndex==-1)
    {
        std::cout<<"Cannot add the personal contact. The Phonebook is full"<<'\n';
        return false;
    }
    else
        {
            if(type=="P")
                {
                    std::string fNameIn, lNameIn, dobIn, emailIn, phoneIn;
                    word>>fNameIn>>lNameIn>>dobIn>> emailIn>>phoneIn;
                    contacts[insertAtIndex]=new PersonalContact(fNameIn, lNameIn, dobIn, emailIn, phoneIn);
                    numContacts++;
                    return true;
                }
            else if(type=="B")
                {
                    std::string bNamein, cityIn, emailIn, phoneIn;
                    word>>bNamein>>cityIn>>emailIn>>phoneIn;
                    contacts[insertAtIndex]=new BusinessContact(bNamein, cityIn, emailIn, phoneIn);
                    numContacts++;
                    return true;
                }
        }
}

bool Phonebook::deleteContact(const string &_phoneNumber)
{
    int toDelete=findContactPosition(_phoneNumber);
    if(toDelete==-1)
        {
            std::cout<<"Cannot find the phone number in the phonebook"<<'\n';
            return false;
        }
    else
        {
            for(int i=toDelete; i<numContacts; i++)
                {
                    contacts[i]=contacts[i+1];
                }
            numContacts--;
            contacts[numContacts]=nullptr;
            return true;
        }
}
void Phonebook::print() const
{
    std::cout<<"Contacts: "<<'\n';
    for(int i=0; i<numContacts; i++)
    {
        contacts[i]->print();
    }
}


// Write the implementation of the readFromFile method here
bool Phonebook::readFromFile(const string &filename)
{
    std::string type, line;
    std::ifstream readFile;
    readFile.open(filename);
    if(readFile.is_open())
        {
            while(!readFile.eof())
                {
                    readFile>>type;
                    getline(readFile, line);
                    addContact(type, line);
                }
            return true;
        }
    else if(!readFile.is_open())
        return false;

    readFile.close();
}


bool Phonebook::operator==(const Phonebook &RHS)
{
    bool toReturn;
    if(size!=RHS.size || numContacts!=RHS.numContacts)
        toReturn=false;
    for( int i=0; i<numContacts; i++)
        {
            if(*contacts[i]!=*RHS.contacts[i])
                toReturn=false;
        }
    return toReturn;
}

Phonebook::~Phonebook()
{
    delete [] contacts;
    contacts=nullptr;
}