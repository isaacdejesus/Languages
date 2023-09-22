const numRescueBoats = (people: number[], limit: number): number =>{
    people.sort((a, b) => a - b);
    let result = 0;
    let left = 0;
    let right = people.length - 1;
    while(left <= right)
    {
        let remain = limit - people[right];
        right --;
        result++;
        if(left <= right && remain >= people[left])
            left++;
    }
    return result;
};