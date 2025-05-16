const wordPattern = (pattern: string, s: string): boolean =>{
    let word_count: number = 0;
    for(let i = 0; i < s.length; i++)
    {
        if(s[i] === ' ')
            word_count++;
    }
    word_count++;
    if(pattern.length !== word_count)
        return false;
    const char_word = new Map<string, string>();
    const word_char = new Map<string, string>();
    let j: number = 0;
    let current_word: string = "";
    for(let i = 0; i < pattern.length; i++)
    {
        current_word = "";
        while(j < s.length)
        {
            if(s[j] === ' ')
            {
                j++;
                break;
            }
            current_word+= s[j];
            j++;
        }
        if(char_word.has(pattern[i]) && char_word.get(pattern[i]) !== current_word)
            return false;
        if(word_char.has(current_word) && word_char.get(current_word) !== pattern[i])
            return false;
        char_word.set(pattern[i], current_word);
        word_char.set(current_word, pattern[i]);
    }
    return true;

};
