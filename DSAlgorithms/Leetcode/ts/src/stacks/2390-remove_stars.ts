const removeStars = (s: string): string =>{
    const a_stack: string[] = [];
    for(let i = 0; i < s.length; i++)
    {
        if(s[i] === "*")
        {
            if(a_stack.length > 0)
                a_stack.pop();
        }
        else
            a_stack.push(s[i]);
    }
    let result = "";
    while(a_stack.length > 0)
    {
        result = a_stack[a_stack.length - 1] + result;
        a_stack.pop();
    }
    return result;
};