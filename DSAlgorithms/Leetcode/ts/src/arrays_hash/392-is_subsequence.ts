const isSubsequence = (s: string, t: string): boolean => {
   let first: number = 0;
   for(let current = 0; current < t.length; current++) 
   {
       if(s[first] === t[current])
            first++;
   }
   if(first >= s.length)
        return true;
    return false;
};
