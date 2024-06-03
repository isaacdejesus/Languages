const remove_duplicates = (arr: number[]) =>
{
    let next_duplicate = 1;
    let i = 1;
    while (i < arr.length)
    {
        if(arr[next_duplicate - 1] !== arr[i])
        {
            arr[next_duplicate] = arr[i];
            next_duplicate ++;
        }
        i++;
    }
    return next_duplicate;
}
console.log(remove_duplicates([2, 3, 3, 3, 6, 9, 9]));
console.log(remove_duplicates([2, 2, 2, 11]));
