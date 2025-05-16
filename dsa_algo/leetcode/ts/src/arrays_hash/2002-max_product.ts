const maxProduct = (s: string): number =>{
    const s_length: number = s.length;
    const hash = new Map<number, number>();
    for(let i = 1; i < Math.pow(2, s_length); i++) 
    {
        let subseq: string = "";
        for(let j = 0; j < s_length; j++)
        {
            if(i & (Math.pow(2, j)))
                subseq += s[j];
        }
        let reversed: string = subseq;
        reversed = reversed.split("").reverse().join("");
        if(reversed === subseq)
        {
            console.log(reversed, "=", subseq);
            hash.set(i, subseq.length);
            console.log("adding : ", i, " ", subseq.length);
        }
    }
    let result: number = 0;
    /*
    hash.forEach((value1, key1) => {
        hash.forEach((value2, key2) => {
            if((key1 & key2) === 0)
                result = Math.max(result, value1 * value2);
        })
    })
    */
    for(let [key1, value1] of hash)
    {
        for(let [key2, value2] of hash)
        {
            if((key1 & key2) === 0)
                result = Math.max(result, value1 * value2);
        }
    }
    return result;
};