const validParenthesis = (s: string): boolean => {
    let map = new Map();
    map.set('{', '}');
    map.set('(', ')');
    map.set('[', ']');
    let b = [];
    for( let i = 0; i < s.length; i++ ){
        if(map.has(s.charAt(i)))
            b.push(s.charAt(i));
        else {
            let pop = b.pop();
            if(map.get(pop) !==s.charAt(i))
                return false;
        }
    }
    return b.length === 0;
};

const validP = (s: string): boolean => {
    const matching: {[key: string]: string} = {"(" : ")", "{" : "}", "[" :"]"};
    const stack: string[] = [];
    for(const char of s) {
        if(matching[char])
            stack.push(char);
        else if (char !== matching[stack[stack.length - 1]])
            return false;
        else stack.pop();
    }
    return stack.length === 0;
};

console.log(validP("{]"));
