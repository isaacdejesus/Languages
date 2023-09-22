const mergeAlternately = (word1: string, word2: string): string =>{
    let i = 0;
    let j = 0;
    let result: string = "";
    while(i < word1.length && j < word2.length)
    {
        result += word1[i];
        result += word2[j];
        i++;
        j++;
    }
    result += word1.substring(i);
    result += word2.substring(j);
    return result;
};