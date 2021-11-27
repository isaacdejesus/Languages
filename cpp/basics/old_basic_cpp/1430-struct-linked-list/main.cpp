#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

struct entry {
   char name[12]="";
   char phone_num[90]="";
   struct entry *next_node=NULL;
};

struct entry list_head;
struct entry *list_current_node;

void displayListContents(struct entry *list_head) {
//save the head in list_head
  list_head=list_current_node;
  while (list_current_node!=NULL) {
      std::cout << list_current_node->name << "\n";
      list_current_node=list_current_node->next_node;
  }
  //save head in current to be used in other functions
  list_current_node=list_head;
}
void readFile(struct entry *list_head,char *filename) {
    list_head=nullptr;
    list_current_node=nullptr;
    std::ifstream readFile;
    std::string line;
    char name[12]="";
    char phone[90]="";
  
    readFile.open(filename);
    while(getline(readFile, line))
    {
      //avoid creating entries for empty lines
      if(line==" ")
        continue;
      std::stringstream s(line);
      while(s>>name>>phone)
        {
          entry *newEntry= new entry;
          strcpy(newEntry->name, name);
          strcpy(newEntry->phone_num, phone);
          newEntry->next_node=nullptr;
          //std::cout<<"Creating new struct containing "<<newEntry->name<<" "<<newEntry->phone_num<<'\n';

          if(list_head==nullptr)
            {
              //std::cout<<"Head was located at address: "<<list_head<<'\n';
              list_head=newEntry;
              list_current_node=newEntry;
              //std::cout<<list_head->name<<'\n';
              //std::cout<<"head is located at address:  "<<list_head<<'\n';
            }
            else
            {
              list_current_node->next_node=newEntry;
              list_current_node=list_current_node->next_node;
            }
            
        }
    }
    readFile.close();
    //save the head in current. This way we can have access to the head outside of this function. 
    list_current_node=list_head;
}

char* entrySearch(struct entry *list_head,char searchTerm[90]) {
    //create a char pointer to return
    char * toReturn= new char[90];
    //save the head in list_head
    list_head=list_current_node;
    //cout<<"Current is pointing to: "<<list_current_node->name;
    entry *trail=nullptr;
    while(list_current_node!=nullptr)
      {
        if(strcmp(list_current_node->name,searchTerm)==0)
          {
            //save the info in trail.
            trail=list_current_node;
          }
        list_current_node=list_current_node->next_node;
      }
      if(trail!=nullptr)
        {
          //if we find the name, we save it in trail, therefore it is not null. if trail is null, then we did not find it.
          toReturn=trail->phone_num;
        }
      else if(trail==nullptr)
      {
        std::cout<<"Name not found in the list."<<'\n';
        toReturn=nullptr;
      }
    //save the head in current to be used in other functions
    list_current_node=list_head;
    return toReturn;
}

void saveResults(char *results){
  std::ofstream writeToFile("fileout.txt");
  if(writeToFile.is_open())
    {
      writeToFile<<"The phone number of the person you searched for is: "<<results<<'\n';
    }

  else
    std::cout<<"Unable to open the file."<<'\n';

  writeToFile.close();
}
int main(int argc, char **argv) {
  //cout<<"list_head is originally stored at address: "<<&list_head<<'\n';
   readFile(&list_head,argv[1]);
   displayListContents(&list_head);
  char searchTerm[90];
  std::cin >> searchTerm;
  char *results =  entrySearch(&list_head,searchTerm);
  saveResults(results);
   return 0;
}