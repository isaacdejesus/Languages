const word_concat = (str: string, words: string[]) => {
    if(words.length === 0 || words[0].length === 0)
        return [];
    const word_freq = new Map<string, number>();
    words.forEach((word) => {
        if(!word_freq.has(word))
            word_freq.set(word, 1);
        else
        {
            const current = word_freq.get(word);
            if(current !== undefined)
                word_freq.set(word, current + 1);
        }
    });
    const result_indices: number[] = [];
    const words_count = words.length;
    const word_length = words[0].length;
    for(let i = 0; i < (str.length - words_count * word_length) + 1; i++)
    {
        const words_seen = new Map<string, number>();
        for(let j = 0; i < words_count; j++)
        {
            let next_word_index = i + j * word_length;
            let word = str.substring(next_word_index, next_word_index + word_length);
            if(!word_freq.has(word))
                break;
            if(!words_seen.has(word))
                words_seen.set(word, 1);
            else
            {
                const current = words_seen.get(word);
                if(current !== undefined)
                    words_seen.set(word, current + 1);
            }
            const a = words_seen.get(word);
            const b = word_freq.get(word);
            if(a !== undefined && b !== undefined )
                if(a > (b || 0))
                    break;
            if(j + 1 === words_count)
                result_indices.push(i);
        }
    }
    return result_indices;
}
console.log(word_concat('catfoxcat', ['cat', 'fox']));
console.log(word_concat('catcatfoxfox', ['cat', 'fox']));
