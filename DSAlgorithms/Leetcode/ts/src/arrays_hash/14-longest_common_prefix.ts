const longestCommonPrefix = (strs: string[]): string =>{
    let result: string = "";
    for(let i = 0; i < strs[0].length; i++)
    {
        for(let s = 0; s < strs.length; s++)
        {
            if(i === strs[s].length || strs[s][i] !== strs[0][i])
                return result;
        }
        result+= strs[0][i];
    }
    return result;
};
