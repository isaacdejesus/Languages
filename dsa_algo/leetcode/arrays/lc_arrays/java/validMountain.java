class validMountain {
    public boolean valid_mountain(int[] arr) {
        boolean decline_found = false;
        if(arr.length < 3 || arr[0] > arr[1]) //check arr doesn't start in decline
            return false;
        for(int i = 1; i < arr.length; i++)
        {
            if(arr[i] == arr[i - 1])  //check that values do not repeat
                return false;
            if(!decline_found && arr[i] < arr[i - 1]) //decline found
                decline_found = true;
            if(decline_found && arr[i] > arr[i - 1]) //check arr not in incline again
                return false;
        }
        return decline_found;
    }
}