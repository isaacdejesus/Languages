const validateStackSequences = (pushed: number[], popped: number[]): boolean =>{
    const a_stack: number[] = [];
    let j = 0;
    for(let i = 0; i < pushed.length; i++)
    {
        a_stack.push(pushed[i]);
        while(j < popped.length && a_stack.length > 0 && popped[j] === a_stack[a_stack.length - 1])
        {
            a_stack.pop();
            j++;
        }
    }
    return a_stack.length < 1;

};