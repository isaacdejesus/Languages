const fullJustify = (words: string[], maxWidth: number): string[] =>{
    const result:string [] = [];
    const current_line: string [] = [];
    let current_line_length: number = 0;
    let i: number = 0;
    while( i < words.length)
    {
       if((current_line_length + current_line.length + words[i].length)  > maxWidth)
       {
           let extra_space = maxWidth - current_line_length;
           let spaces = Math.floor(extra_space / Math.max(1, current_line.length - 1));
           let remainder = extra_space % Math.max(1, current_line.length - 1);
           for(let j = 0; j < (Math.max(1, current_line.length - 1)); j++)
           {
               current_line[j] += " ".repeat(spaces);
               if(remainder > 0)
               {
                   current_line[j] += " ";
                   remainder -= 1;
               }
           }
           result.push(current_line.join(""));
           current_line.length = 0;
           current_line_length = 0;
       }
       current_line.push(words[i]);
       current_line_length += words[i].length;
       i++;
    }
    let last_line = current_line.join(" ");
    let trail_space = maxWidth - last_line.length;
    result.push(last_line + " ".repeat(trail_space));
    return result;

};