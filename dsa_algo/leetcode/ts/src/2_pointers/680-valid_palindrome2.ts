const validPalindrome = (s: string): boolean =>{
    let left = 0;
    let right = s.length - 1;
    while(left < right)
    {
        if(s[left] !== s[right])
        {
            let skip_left: string = s.substring(left + 1, right + 1);
            let skip_right: string = s.substring(left, right);
            let left_reversed: string = skip_left;
            let right_reversed: string = skip_right;
            left_reversed = left_reversed.split("").reverse().join("");
            right_reversed = right_reversed.split("").reverse().join("");
            return (skip_left === left_reversed || skip_right === right_reversed);
        }
        left ++;
        right --;
    }
    return true;
    };