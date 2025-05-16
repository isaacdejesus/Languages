const climbingStairs = (n:number): number => {
    let one = 1;
    let two = 1;
    let temp;
    while(n > 1)
    {
        temp = one;
        one = one + two;
        two = temp;
        --n;
    }
    return one;
}

const climbingStairs2 = (n: number):number => {
    let one = 1; 
    let two = 1;
    let temp;
    for(let i = 0; i < n - 1; i++)
    {
        temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}