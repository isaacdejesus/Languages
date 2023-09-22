const isPalindrome = (s: string): boolean => {
    const regex = /[\W_]/g;
    let cleaned = s.toLowerCase().replace(regex, "");
    let rev = cleaned.split("").reverse().join("");
    if(rev === cleaned) return true;
    return false;
};


const isPalindrome2 = (s: string): boolean => {
    //strip s from nonalphanumeric chars
    //set all chars to lowercase
    s = s.replace(/[^0-9A-Za-z]/g, '').toLowerCase();
    let end: number = s.length - 1;
    for(let i: number = 0; i <= end; i +=1, end -= 1)
        if(s[i] !== s[end])
            return false;
    return true;
};


const isPalindrome3 = (s: string): boolean => {
    s = s.toLowerCase().replace(/[W_]/g, '');
    return s === s.split('').reverse().join('');
}; 
