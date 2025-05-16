const is_alpha_num = (c: string): boolean =>
{
    const a = "a";
    const z = "z";
    const A = "A";
    const Z = "Z";
    const zero = "0";
    const nine = "9";
    return((A.charCodeAt(0) <= c.charCodeAt(0) && c.charCodeAt(0)<= Z.charCodeAt(0)) || 
            (a.charCodeAt(0) <= c.charCodeAt(0) && c.charCodeAt(0) <= z.charCodeAt(0)) ||
            (zero.charCodeAt(0) <= c.charCodeAt(0) && c.charCodeAt(0) <= nine.charCodeAt(0)));
}
const isPalindrome = (s: string): boolean => {
    let left = 0;
    let right = s.length - 1;
    while(left < right)
    {
        while( left < right && !is_alpha_num(s[left]))
            left += 1;
        while(right > left && !is_alpha_num(s[right]))
            right -= 1;
        if(s[left].toLowerCase() !== s[right].toLowerCase())
            return false;
        left += 1;
        right -= 1;
    }
    return true;
};