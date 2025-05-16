const evalRPN = (tokens: string[]): number =>{
    const a_stack: number[] = [];
    for(let i = 0; i < tokens.length; i++)
    {
        let c = tokens[i];
        if(c === "+")
        {
            let right = a_stack[a_stack.length - 1];
            a_stack.pop();
            let left = a_stack[a_stack.length - 1];
            a_stack.pop();
            a_stack.push(left + right);
        }
        else if(c === "-")
        {
            let right = a_stack[a_stack.length - 1];
            a_stack.pop();
            let left = a_stack[a_stack.length - 1];
            a_stack.pop();
            a_stack.push(left - right);
        }
        else if(c ==="*")
        {
            let right = a_stack[a_stack.length - 1];
            a_stack.pop();
            let left = a_stack[a_stack.length - 1];
            a_stack.pop();
            a_stack.push(left * right);
            //console.log(typeof(a_stack[a_stack.length -1]));
        }
        else if(c ==="/")
        {
            let right = a_stack[a_stack.length - 1];
            a_stack.pop();
            let left = a_stack[a_stack.length - 1];
            a_stack.pop();
            a_stack.push(Math.trunc(left / right));
        }
        else
        {
            a_stack.push(Number(c));
        }
    }
    return a_stack[a_stack.length - 1];

};