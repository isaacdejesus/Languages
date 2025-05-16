const dailyTemperatures = (temperatures: number[]): number[] =>{
    const temp_stack: number[] = [];
    const index_stack: number[] = [];
    const result: number[] = new Array(temperatures.length).fill(0);
    for(let i = 0; i < temperatures.length; i++)
    {
        while(temp_stack.length > 0 && temperatures[i] > temp_stack[temp_stack.length - 1])
        {
            let temp = temp_stack[temp_stack.length - 1];
            let index = index_stack[index_stack.length - 1];
            temp_stack.pop();
            index_stack.pop();
            result[index] = (i - index);
        }
        temp_stack.push(temperatures[i]);
        index_stack.push(i);
    }
    return result;

};