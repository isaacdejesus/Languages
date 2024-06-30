const circular_arr_loop = (arr)=> {
    for(let i = 0; i < arr.length; i++) 
    {
        let is_forward = arr[i] >= 0;
        let slow = i;
        let fast= i;
        while(true)
        {
            slow = find_next_index(arr, is_forward, slow);
            fast = find_next_index(arr, is_forward, fast);
            if(fast !== -1)
                fast = find_next_index(arr, is_forward, fast);
            if(slow === -1 || fast === -1 || slow === fast)
                break;
        }
        if(slow !== -1 && slow === fast)
            return true;
    }
    return false;
}

const find_next_index = (arr, is_forward, current_index) => {
    direction = arr[current_index] >= 0;
    if(is_forward !== direction)
        return -1;
    next_index = (current_index + arr[current_index]) % arr.length;
    if(next_index < 0)
        next_index += arr.length;
    if(next_index === current_index)
        next_index--;
    return next_index;
}

console.log(circular_arr_loop([1, 2, -1, 2, 2]));
console.log(circular_arr_loop([2, 2, -1, 2]));
console.log(circular_arr_loop([2, 2, -1, -2]));
