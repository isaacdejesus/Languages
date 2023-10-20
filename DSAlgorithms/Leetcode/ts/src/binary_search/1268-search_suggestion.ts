const suggestedProducts = (products: string[], searchWord: string): string[][] =>{
    const result: string[][] = [];
    products.sort();
    let left = 0;
    let right = products.length - 1;
    for(let i = 0; i < searchWord.length; i++)
    {
        let c = searchWord[i];
        while(left <= right && (products[left].length <= i || products[left][i] != c))
            left++;
        while(left <= right && (products[right].length <= i || products[right][i] != c))
            right--;
        let remain = right - left + 1;
        let temp = Math.min(3, remain);
        const t: string[] = [];
        for(let j = left; j < left + temp; j++)
            t.push(products[j])
        result.push(t);
    }
    return result;
};