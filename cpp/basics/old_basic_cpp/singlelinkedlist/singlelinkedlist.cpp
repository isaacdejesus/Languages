#include <iostream>
#include "singlelinkedlist.h"


template <class DataType>
node<DataType>::node()
{
    link=nullptr;
}
template <class DataType>
singlelinkedlist<DataType>::singlelinkedlist()
{
    count=0;
    head=nullptr;
    tail=nullptr;
}

template <class DataType>
bool singlelinkedlist<DataType>::isEmpty()
{
    return(head==nullptr);
}

template <class DataType>
void singlelinkedlist<DataType>::display()
{
    //create pointer to head
    node<DataType> *current= head;

    //cycle through list
    while(current !=nullptr)
        {
            std::cout<<current->info<<" ";
            current=current->link;
        }
    std::cout<<'\n';
}

template <class DataType>
void singlelinkedlist<DataType>::printInfoAtNode(node <DataType> *val)
{
    std::cout<<val->info;
    std::cout<<'\n';
}

template <class DataType>
void singlelinkedlist<DataType>::addAtBeginning(DataType info)
{
    node<DataType> *current= head;
    node<DataType> *newNode= new node<DataType>;

    newNode->info=info;
    newNode->link=nullptr;

    //if list is empty, new entry becomes first node

    if(isEmpty())
    {
        head=newNode;
        tail=newNode;
        count++;
    }

    //if there's an existing node, new node links to head and new node becomes the new head
    else
    {
         newNode->link=current;
         head=newNode;
         count++;
    }
    
}

//adds new node at end of list
template <class DataType>
void singlelinkedlist<DataType>::addAtEnd( DataType info)
{
    node<DataType> *current=head;
    node<DataType> *newNode=new node<DataType>;
    newNode->info=info;
    newNode->link=nullptr;

    //if list is empty, new node becomes first
    if(isEmpty())
    {
        head=newNode;
        tail=newNode;
        count++;
    }
    //if there are existing nodes, cycle through list and have last node link to new node
    else
    {
        while(current->link!= nullptr)
        {
            current=current->link;
        }
        current->link=newNode;
        tail=newNode;
        count++;
    }
}

//adds new node at specified index between 1 and end of list
//if index is<2, new node is added to the head
//if index is greater than number of existing nodes, new node is added to the end
template <class DataType>
void singlelinkedlist<DataType>::addAtIndex(DataType info, int index)
{
    node<DataType> *current=head;
    node<DataType> *newNode=new node<DataType>;

    newNode->info=info;
    newNode->link=nullptr;

    //if empty new node becomes first node
    if(isEmpty())
    {
        std::cout<<"List is empty: Adding entry to list.";
        head=newNode;
        tail=newNode;
        count++;
    }

    //if index is greater than number of existing nodes, new node is added to the end
    else if(index>count)
    {
        std::cout<<"Index is out of range: Adding entry to the end of the list.";
        while(current->link!=nullptr)
        {
            current=current->link;
        }
        current->link=newNode;
        tail=newNode;
        count++;
    }
    //if index <2, add to the head of linked list
    else if(index<2)
    {
        newNode->link= current;
        head=newNode;
        count++;
    }
    else
    {
        for(int i=1; i<index-1; i++)
        {
            current=current->link;
        }
        newNode->link=current->link;
        current->link=newNode;
        count++;
    }
    std::cout<<'\n';
}

//adds node before speicfied index. if index is <2, node is added to the head
//if given index is greater than existing nodes, new node is added to the end
template <class DataType>
void singlelinkedlist<DataType>::addBeforeIndex(DataType info, int index)
{
    node<DataType> *current=head;
    node<DataType> *newNode=new node<DataType>;

    newNode->info=info;
    newNode->link=nullptr;

    //if empty, add new node to list
    if(isEmpty())
    {
        std::cout<<"List is empty: Adding entry to list.";
        head=newNode;
        tail=newNode;
        count++;
    }
    //if index greater than existing number of nodes, add new node to the end
    else if(index>count)
    {   
        std::cout<<"Index is out of range: Adding entry to the end of the list.";
        while(current->link!=nullptr)
            {
                current=current->link;
            }
        current->link=newNode;
        tail=newNode;
        count++;
    }
    //if index<2, add to the head
    else if(index<2)
        {
            newNode->link=current;
            head=newNode;
            count++;
        }
        //else cycle through linked list and add new node before specified index
    else
    {
        for(int i=1; i<index-2; i++)
        {
            current=current->link;
        }
        newNode->link=current->link;
        current->link=newNode;
    }
    std::cout<<'\n';
}

template <class DataType>
void singlelinkedlist<DataType>::addAfterIndex(DataType info, int index)
{
    node<DataType> *current=head;
    node<DataType> *newNode= new node<DataType>;

    newNode->info=info;
    newNode->link=nullptr;

    //if empty, add new node to list
    if(isEmpty())
        {
            std::cout<<"List is empty: Adding entry to list.";
            head=newNode;
            tail=newNode;
            count++;
        }
    //if index greater tjan number of nodes, add node at end of list
    else if(index>count)
        {
            std::cout<<"Index is out of range: Adding entry to end of list.";
            while(current->link!=nullptr)
                {
                    current=current->link;
                }
            current->link=newNode;
            tail=newNode;
            count++;
        }
    //else cycle through list and add node at specified index
    else
    {
        for(int i=1; i<index; i++)
            {
                current=current->link;
            }
            newNode->link=current->link;
            current->link=newNode;
            count++;
    }
    std::cout<<'\n';
}

template <class DataType>
int singlelinkedlist<DataType>::search(DataType toFind)
{
    node <DataType> *current=head;
    int index=1;
    if(isEmpty())
        {
            std::cout<<"Can not search an empty list"<<'\n';
            index=-1;
        }
    else if(current->info==toFind)
            index=1;
    else
        {
            while(current->link!=nullptr && current->info!=toFind)
                {
                    current=current->link;
                    index++;
                }
            if(current->link==nullptr && current->info!=toFind)
                index=-1;
        }
    return index;
}

template <class DataType>
node <DataType> *singlelinkedlist<DataType>::objectAtIndex( int index)
{
    node <DataType> *current= head;
    node <DataType> *returnNode;

    if( index<=count && index >0)
    {
        //std::cout<<"not here?";
    int count=1;
    while(current->link!=nullptr && count <index)
        {
            current=current->link;
            count++;
        }
    
    returnNode=current;
    //std::cout<<returnNode->info;
    }
    //std::cout<<'\n';
    return returnNode;
}

template <class DataType>
void singlelinkedlist<DataType>::addInOrder(DataType info)
{
    node <DataType> *current=head;
    node <DataType> *trail;
    node <DataType> *newNode= new node<DataType>;
    newNode->info=info;
    newNode->link=nullptr;
    if(isEmpty())   
        {
            head=newNode;
            tail=newNode;
            count++;
        }
    else if(head->info>info)
        {
            newNode->link=head;
            head=newNode;
            count++;
        }
    else
        {
            while(current->link!=nullptr && current->info<info)
                {
                    trail=current;
                    current=current->link;
                }
            if(current->link!=nullptr)
                {
                    newNode->link=trail->link;
                    trail->link=newNode;
                    count++;
                }
            else if(current->link==nullptr)
                {
                    current->link=newNode;
                    tail=newNode;
                    count++;
                }
        }
}

template <class DataType>
void singlelinkedlist<DataType>::swapNodes(node<DataType> *val1, node <DataType> *val2)
{
    node<DataType> *current=head;
    node <DataType> *trail=nullptr;

    if(val1->info==head->info && val2->info==tail->info)
        {
            while(current->link!=nullptr && current->info!=val2->info)
                {
                    trail=current;
                    current=current->link;
                }
            val2->link=val1->link;
            val1->link=nullptr;
            tail=val1;
            head=val2;
            trail->link=val1;
            //delete val1, val2;
        }
    else if(head->info==val1->info)
        {
            while(current->link!=nullptr && current->info!=val2->info)
                {
                    trail=current;
                    current=current->link;
                }
            node <DataType> *temp= val1->link;
            val1->link=current->link;
            trail->link=val1;
            val2->link=temp;
            head=val2;
        }
    else
        {
            node <DataType> *trail2= nullptr;
            node <DataType> *temp= nullptr;           
            while(current->link!=nullptr && current->info!=val1->info)
                {
                    trail=current;
                    current=current->link;
                }
            current=nullptr;
            current=head;
            while(current->link!=nullptr && current->info!=val2->info)
                {
                    trail2=current;
                    current=current->link;
                }
            temp=val1->link;
            val1->link=current->link;
            trail2->link=val1;
            val2->link=temp;
            trail->link=val2;
            //delete stuff
        }
}

template <class DataType>
void singlelinkedlist<DataType>::swapInfo(node<DataType> *val1, node <DataType> *val2)
{
    DataType temp= val1->info;
    val1->info=val2->info;
    val2->info=temp;
    //delete temp;
}
template <class DataType>
void singlelinkedlist<DataType>::bubbleSort()
{
    node<DataType> *current=head;
    node<DataType> *ahead=nullptr;
    
    for(int i=0; i<count; i++)
    {
	    current=head;
	    ahead=current->link;
	    for(int j=0; j<count-1; j++)
	    {
		ahead=current->link;
		if(ahead==nullptr)
			break;
		if(current->info>ahead->info)
			swapInfo(current, ahead);
		current=current->link;
	    }
    }
}
//this must be changed according to data to be stored in linked list
//right now the list is set to hold strings
template class node <std::string>;
template class singlelinkedlist <std::string>;
template class node <int>;
template class singlelinkedlist <int>;
template class node <float>;
template class singlelinkedlist <float>;
template class node <char>;
template class singlelinkedlist <char>;
