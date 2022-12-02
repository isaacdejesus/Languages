const validAnagram = (s: string, t: string): boolean =>{
    let map = new Map<string, number>();
    if(s.length !== t.length)
        return false;
    for(let i = 0; i < s.length; i++){
        const character = s.charAt(i);
        if(map.has(character))
            map.set(character, map.get(character)! + 1)
        else
            map.set(character, 1);
    }
    for(let i = 0; i < t.length; i++) {
        const character = t.charAt(i);
        if(map.has(character))
            map.set(character, map.get(character)! - 1);
        else
            return false;
    }
    for(let i of map.values())
        if(i != 0)
            return false;
    return true;
};
const validAnagram2 = (s: string, t: string): boolean =>{
    if(s.length != t.length)
        return false;
    const lookup: { [string: string]: number } = {};
    for(let i = 0; i < s.length; i++){
        if(lookup[s[i]])
            lookup[s[i]] += 1;
        else 
            lookup[s[i]] = 1
    }
    for(let i = 0; i < t.length; i++){
        if(lookup[t[i]])
            lookup[t[i]] = lookup[t[i]] - 1;
        else
            return false;
    }
    return true;
};
