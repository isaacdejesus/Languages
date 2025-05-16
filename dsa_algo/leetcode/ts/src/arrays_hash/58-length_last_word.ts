const lengthOfLastWord =(s: string): number =>{
    let last_word_length = 0;
    for(let i = s.length - 1; i >= 0; i--)
    {
        if(s[i] !== ' ')
            last_word_length++;
        if(last_word_length > 0 && s[i] === ' ')
            break;
    }
    return last_word_length;
};
