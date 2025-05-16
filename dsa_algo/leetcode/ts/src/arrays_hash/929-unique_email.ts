const numUniqueEmails = (emails: string[]): number =>{
    const a_set = new Set<string> ();
    for(let i = 0; i < emails.length; i++)
    {
        const index_of_at = emails[i].indexOf("@");
        const base_local = emails[i].substring(0, index_of_at);
        const domain = emails[i].substring(index_of_at + 1);
        const local_without_dots = base_local.replaceAll('.', '');
        const index_of_plus = local_without_dots.indexOf('+');
        let local_without_plus: string = '';
        if(index_of_plus !== -1)
            local_without_plus = local_without_dots.substring(0, index_of_plus);
        else
            local_without_plus = local_without_dots;
        
        const final_email = local_without_plus + '@' + domain;
        a_set.add(final_email);
    }
    return a_set.size;
};
