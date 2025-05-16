const removeDuplicates = (s: string, k: number): string =>{
    const char_stack: string[] = [];
    const count_stack: number[] = [];
    for(let i = 0; i < s.length; i++)
    {
        if(char_stack.length > 0 && char_stack[char_stack.length - 1] === s[i])
            count_stack[count_stack.length - 1 ]++;
        else
        {
            char_stack.push(s[i]);
            count_stack.push(1);
        } 
        if(count_stack[count_stack.length - 1] === k)
        {
            count_stack.pop();
            char_stack.pop();
        }
    }
    let result = "";
    while(char_stack.length > 0)
    {
        let temp = "";
        for(let i = 0; i < count_stack[count_stack.length - 1]; i++)
        {
            temp += char_stack[char_stack.length - 1];
        }
        result = temp + result;
        char_stack.pop();
        count_stack.pop();
    }
    return result;
};