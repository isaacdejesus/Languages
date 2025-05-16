const {Deque} =  require('@datastructures-js/deque');
//doesn't work idk why
const find_subarrys = (arr: number[], target: number) => {
    let result = [];
    let product = 1;
    let left = 0;
    for(let right = 0; right < arr.length; right++)
    {
        product *= arr[right];
        while((product >= target && left < arr.length))
        {
            product /= arr[left];
            left++;
        }
        const temp_list = new Deque();
        //const temp_list = []
        for(let i = right; i > left - 1; i--)
        {
            temp_list.pushFront(arr[i]);
            result.push(temp_list.toArray());
            //temp_list.unshift(arr[i]);
            //result.push(temp_list);
        }
    }
    return result;
}
console.log(find_subarrys([2, 5, 3, 10], 30));
console.log(find_subarrys([8, 2, 6, 5], 50));
