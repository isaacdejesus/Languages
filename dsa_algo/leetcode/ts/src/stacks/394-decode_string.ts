const decodeString = (s: string): string =>{
    let result = "";
    const stack: string[] = [];
    for(let i = 0; i < s.length; i++)
    {
        if(s[i] !== "]")
            stack.push(s[i]);
        else
        {
            let temp = "";
            while(stack[stack.length - 1] != "[")
            {
                temp = stack[stack.length - 1] + temp;
                stack.pop();
            }
            stack.pop(); //pops the [
            let k = "";
            while(stack.length > 0 && Number.isInteger(+stack[stack.length - 1]))
            {
                k = stack[stack.length -1] + k;
                stack.pop();
            }
            let k_ = Number(k);
            for(let i = 0; i < k_; i++)
                stack.push(temp);
        }
    }
    while(stack.length > 0)
    {
        result = stack[stack.length - 1] + result;
        stack.pop();
    }
    return result;
};