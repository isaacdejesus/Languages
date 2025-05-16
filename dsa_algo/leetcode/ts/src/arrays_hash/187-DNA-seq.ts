const findRepeatedDnaSequences = (s: string): string[] =>{
    const a_set = new Set<string>();
    const answer_set = new Set<string>();
    const result: string[] = [];
    const s_size: number = s.length;
    for(let left = 0; left < (s_size - 9); left++)
    {
        let current: string = s.substr(left, 10);
        if(a_set.has(current))
            answer_set.add(current);
        a_set.add(current);
    }
    answer_set.forEach(item => {
        result.push(item);
    })
    return result;
};