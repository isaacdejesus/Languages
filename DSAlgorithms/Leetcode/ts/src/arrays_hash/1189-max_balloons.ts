const maxNumberOfBalloons = (text: string): number =>{
    const input_hash = new Map<string, number>();
    const donor_hash = new Map<string, number>();
    const input_string: string = "balloon";
    for(let i = 0; i < input_string.length; i++)
    {
        if(input_hash.has(input_string[i]))
        {
            const current_val = input_hash.get(input_string[i]);
            input_hash.set(input_string[i], current_val + 1);
        }
        else
            input_hash.set(input_string[i], 1);
    }
    for(let i = 0; i < text.length; i++)
    {
        if(donor_hash.has(text[i]))
        {
            const current_val = donor_hash.get(text[i]);
            donor_hash.set(text[i], current_val + 1);
        }
        else 
            donor_hash.set(text[i], 1);
    }
    let result: number = text.length;
    input_hash.forEach((value, key) => {
        const donor_value = donor_hash.get(key);
        console.log(donor_value);
        console.log(value);
        if(donor_value !== undefined)
            result = Math.min(result, Math.floor(donor_value / value));
        else
            result = Math.min(result, 0 / value);
    })
    return result;

};
