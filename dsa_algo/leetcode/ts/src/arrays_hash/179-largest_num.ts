const  largestNumber = (nums: number[]): string =>{
    let largest = nums
        .map((n) => n.toString())
        .sort((x: any, y:any) => y + x - (x + y))
        .join('');

    return largest[0] === '0' ? '0' : largest;
};