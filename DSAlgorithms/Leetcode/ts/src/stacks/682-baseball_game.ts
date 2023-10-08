const calPoints = (operations: string[]): number =>{
    const a_stack: number[] = [];
    for(let i = 0; i < operations.length; i++)
    {
        let c = operations[i];
        if(c === "+")
        {
            let right = a_stack[a_stack.length - 1];
            let left = a_stack[a_stack.length - 2];
            a_stack.push(left + right);
        }
        else if(c === 'D')
        {
            let top = a_stack[a_stack.length - 1];
            a_stack.push(top * 2);
        }
        else if(c === "C")
            a_stack.pop();
        else
            a_stack.push(Number(c));
    }
    let result = 0;
    while(a_stack.length > 0)
    {
        result += a_stack[a_stack.length - 1];
        a_stack.pop();
    }
    return result;
};