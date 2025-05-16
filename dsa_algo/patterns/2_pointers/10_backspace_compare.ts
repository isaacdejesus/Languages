const backspace_compare = (str_1: string, str_2: string) =>
{
    let index_1 = str_1.length - 1;
    let index_2 = str_2.length - 1;
    while(index_1 >= 0 || index_2 >= 0)
    {
        let i_1 = get_next_valid_char_index(str_1, index_1);
        let i_2 = get_next_valid_char_index(str_2, index_2);
        if(i_1 < 0 && i_2 < 0)
            return true;
        if(i_1 < 0 || i_2 < 0)
            return false;
        if(str_1[i_1] !== str_2[i_2])
            return false;
        index_1 = i_1 - 1;
        index_2 = i_2 - 1;
        return true;
    }
}

const get_next_valid_char_index = (str: string, index: number) => 
{
   let backspace_count = 0;
    while(index >= 0)
    {
        if(str[index] === '#')
            backspace_count++;
        else if(backspace_count > 0)
            backspace_count--;
        else
            break;
        index--;
    }
    return index;
}

console.log(backspace_compare('xy#z', 'xzz#'));
console.log(backspace_compare('xy#z', 'xyz#'));
console.log(backspace_compare('xp#', 'xyz##'));
console.log(backspace_compare('xywrrmp', 'xywrrmu#p'));
