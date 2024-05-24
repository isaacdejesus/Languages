const fruits_into_baskets = (fruits: string[])=> {
    let window_start = 0;
    let max_length = 0;
    const fruit_freq = new Map<string, number>();
    for(let window_end = 0; window_end < fruits.length; window_end++)
    {
        const right_fruit = fruits[window_end];
        if(!fruit_freq.has(right_fruit))
            fruit_freq.set(right_fruit, 0);
        else
        {
            const current = fruit_freq.get(right_fruit);
            if(current !== undefined)
                fruit_freq.set(right_fruit, current + 1);
        }
        while(fruit_freq.size > 2)
        {
            const left_fruit = fruits[window_start];
            if(fruit_freq.has(left_fruit) && fruit_freq.get(left_fruit) === 0)
                fruit_freq.delete(left_fruit);
            if(fruit_freq.has(left_fruit))
            {
                const current = fruit_freq.get(left_fruit);
                if(current)
                    fruit_freq.set(left_fruit, current - 1);
            }
            window_start ++;
        }
        max_length = Math.max(max_length, window_end - window_start + 1);
    }
    return max_length;
}
console.log(`Max number of fruits: ${fruits_into_baskets(['A', 'B', 'C', 'A', 'C'])}`);
console.log(`Max number of fruits: ${fruits_into_baskets(['A', 'B', 'C', 'B', 'B', 'C'])}`);
