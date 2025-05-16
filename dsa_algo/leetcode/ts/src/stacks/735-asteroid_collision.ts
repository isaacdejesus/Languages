const asteroidCollision = (asteroids: number[]): number[] =>{
    const a_stack: number[] = [];
    for(let i = 0; i < asteroids.length; i++)
    {
        while(a_stack.length > 0 && asteroids[i] < 0 && a_stack[a_stack.length - 1] > 0)
        {
            let diff = asteroids[i] + a_stack[a_stack.length - 1];
            if(diff < 0)
                a_stack.pop();
            else if(diff > 0)
                asteroids[i] = 0;
            else
            {
                asteroids[i] = 0;
                a_stack.pop();
            }
        }
        if(asteroids[i] !== 0)
            a_stack.push(asteroids[i]);
    }
    return a_stack;
};