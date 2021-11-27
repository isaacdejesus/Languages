#include<iostream>
#include<string>
#include<queue>
#include<vector>
//prohra, simulates hot potato game.
//takes an array of names and an int.
//names enter queue, first person in queue holds potato
//then person passes potato to next person in queue and moves 
//to the back to the queue. 
//Process repeated n times. Whoever is holding potato/first in queue
//is permanently removed from queue
std::string hotPotato(std::vector<std::string>, int);

int main()
{
    std::vector<std::string> participants = {"joe", "jane", "karl", "Isaac", "Garah", "Teresa"} ;
    std::cout<<hotPotato(participants, 7);
    return 0;
}
        
std::string hotPotato(std::vector<std::string> V, int iterations)
{
    std::string returnValue;
    std::string prev;
    std::queue<std::string> a_queue;
    //add names to queue
    for(auto name: V)
        a_queue.push(name);

    while(a_queue.size()>1)
    {
        for(int iteration = 0; iteration <  iterations; iteration ++)
        {
        prev = a_queue.front();
        a_queue.pop();
        a_queue.push(prev);
        }
        a_queue.pop();
    }
    returnValue = a_queue.front();
    return returnValue;
}
