int numUniqueEmails(vector<string>& emails) {
    std::unordered_set<std::string> a_set;
    std::string local_name;
    std::string domain_name;
    for(int i = 0; i < emails.size(); i++) 
    {
        local_name = emails[i].substr(0, emails[i].find('@'));
        domain_name = emails[i].substr(emails[i].find('@'));
        if(local_name.find('+') != std::string::npos) //find returns valid index
            local_name.erase(local_name.find('+'), std::string::npos);
        for(int i = 0; i < local_name.size(); i++)
            if(local_name[i] == '.')
                local_name.erase(i, 1);  //only delete char at index
        std::string final_string = local_name + domain_name;
        a_set.insert(final_string);
    }
    return a_set.size();
    }