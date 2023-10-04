const largestRectangleArea = (heights: number[]): number =>{
    let max_area = 0 ;
    const a_stack: number[][] = [];
    let current_bar: number[] = [];
    let top: number[] = [];
    //console.log(a_stack[0][0])
    for(let i = 0; i < heights.length; i++)
    {
        let start = i;
        if(a_stack.length > 0)
            top = a_stack[a_stack.length - 1];
        while((a_stack.length > 0) && top[1] > heights[i])
        {
            top = a_stack[a_stack.length - 1];
            a_stack.pop();
            max_area = Math.max(max_area, top[1] * (i - top[0]))
            start = top[0];
            if(a_stack.length > 0)
                top = a_stack[a_stack.length - 1];
        }
        current_bar.push(start);
        current_bar.push(heights[i]);
        a_stack.push(current_bar);
        current_bar = [];
    }
    while(a_stack.length > 0)
    {
        top = a_stack[a_stack.length - 1];
        a_stack.pop();
        let temp = top[1] * (heights.length - top[0]);
        max_area = Math.max(max_area, temp);
    }
    return max_area;
};