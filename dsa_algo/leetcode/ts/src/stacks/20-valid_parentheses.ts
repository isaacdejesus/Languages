const isValid = (s: string): boolean =>{
    const hash = new Map<string, string>([["{", "}"], ["(", ")"], ["[", "]"]]);
    const a_stack: string[] = [];
    for(let i = 0; i < s.length; i++) 
    {
        if(hash.has(s[i]))
            a_stack.push(s[i]);
        else
        {
            if(!(a_stack.length > 0))
                return false;
            let c = a_stack[a_stack.length - 1];
            a_stack.pop();
            if(hash.get(c) != s[i])
                return false;
        }
    }
    return a_stack.length < 1;

};