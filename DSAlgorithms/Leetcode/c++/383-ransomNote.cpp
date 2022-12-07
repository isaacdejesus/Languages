#include <iostream>
#include <unordered_map>
bool canConstruct(std::string ransomNote, std::string magazine);
int main()
{
    return 0;
}
bool canConstruct(std::string ransomNote, std::string magazine)
{
    int ransomNoteSize = ransomNote.size();
    int magazineSize = magazine.size();
    std::unordered_map<char, int> hash;
    if(ransomNoteSize > magazineSize)
        return false;
    for(int character = 0; character < magazineSize; character++)
    {
        if(hash[magazine[character]])
            hash[magazine[character]]++;
        else
            hash[magazine[character]] = 1;
    }
    for(int character = 0; character < ransomNoteSize; character++)
    {
        if(hash[ransomNote[character]] && hash[ransomNote[character]] > 0)
            hash[ransomNote[character]]--;
        else
            return false;
    }
    return true;
}