const canConstruct = (magazine: string, ransomNote: string): boolean => {
    const magazineSize = magazine.length;
    const ransomNoteSize = ransomNote.length;
    const hash = new Map<string, number>();
    if(ransomNoteSize > magazineSize)
        return false;
    for(let char = 0; char < magazineSize; char++)
    {
        if(hash.has(magazine[char]))
        {
            let count = hash.get(magazine[char]);
            if(count)
                hash.set(magazine[char], ++count);
        }
        else
            hash.set(magazine[char], 1);
    }
    for(let char = 0; char < ransomNoteSize; char++)
    {
        let count = hash.get(ransomNote[char]);
        if(count && hash.has(ransomNote[char]) && count > 0)
            hash.set(ransomNote[char], --count);
        else
            return false;
    }
    return true;
}