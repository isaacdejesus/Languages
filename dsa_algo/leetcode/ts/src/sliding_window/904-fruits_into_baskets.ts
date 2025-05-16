const totalFruit = (fruits: number[]): number =>{
    const count_hash = new Map<number, number>();
    let left = 0;
    let total = 0;
    let result = 0;
    for(let right = 0; right < fruits.length; right++ )
    {
        if(count_hash.has(fruits[right]))
        {
            const current = count_hash.get(fruits[right]);
            count_hash.set(fruits[right], current + 1);
        }
        else
            count_hash.set(fruits[right], 1);
        total++;
        while(count_hash.size > 2)
        {
            const f = fruits[left];
            if(count_hash.has(f))
            {
                const current = count_hash.get(f);
                count_hash.set(f, current - 1);
            }
            left++;
            if(count_hash.has(f))
            {
                const current = count_hash.get(f);
                if(current < 1)
                    count_hash.delete(f);
            }
            total--;
        }
        result = Math.max(result, total);
    }
    return result;
};