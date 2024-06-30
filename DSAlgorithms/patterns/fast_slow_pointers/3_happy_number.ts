const happy_number = (num: number) => {
    let slow = num;
    let fast = num;
    while(true)
    {
        slow = find_sq_sum(slow);
        fast = find_sq_sum(find_sq_sum(fast));
        if(slow === fast)
            break;
    }
    return slow === 1;
}

const find_sq_sum = (num: number) => {
    let sum = 0;
    while((num > 0))
    {
        let digit = num % 10;
        sum += digit * digit;
        num = Math.floor(num/10);
    }
    return sum;
}

console.log(happy_number(23));
console.log(happy_number(12));
