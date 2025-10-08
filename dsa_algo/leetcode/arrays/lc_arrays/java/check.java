public class check {
    public boolean check_if_exists(int[] arr){
        Set<Integer> seen = new HashSet<>();
        for(int i = 0; i < arr.length; i++)
        {
            if(seen.contains(2 * arr[i]) || (arr[i] % 2 == 0 && seen.contains(arr[i]/2)))
                return true;
            seen.add(arr[i]);
        }
        return false;
    }
}