const remove_element = (arr: number[], key: number) => 
{
    let next_element = 0;
    for(let i = 0; i < arr.length; i++)
    {
        if(arr[i] !== key)
        {
            arr[next_element] = arr[i];
            next_element++
        }
    }
    return next_element;
}
console.log(`Array new length: ${remove_element([3, 2, 3, 6, 3, 10, 9, 3], 3)}`);
console.log(`Array new length: ${remove_element([2, 11, 2, 2, 1], 2)}`);
