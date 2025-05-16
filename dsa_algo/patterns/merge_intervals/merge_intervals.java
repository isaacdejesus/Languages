import java.util.*;
class interval {
    int start;
    int end;
    public interval(int start, int end)
    {
        this.start = start;
        this.end = end;
    }
};

class merge_intervals {
    public static List<interval> merge(List<interval> intervals)
    {
        if(intervals.size() < 2)
            return intervals;
        Collections.sort(intervals, (a, b) -> Integer.compare(a.start, b.start));
        List<interval> merged_intervals = new LinkedList<interval>();
        Iterator<interval> interval_itr = intervals.iterator();
        interval interval_ = interval_itr.next();
        int start = interval_.start;
        int end = interval_.end;
        while(interval_itr.hasNext())
        {
            interval_ = interval_itr.next();
            if(interval_.start <= end)
                end = Math.max(interval_.end, end);
            else
            {
                merged_intervals.add(new interval(start, end));
                start = interval_.start;
                end = interval_.end;
            }
        }
        merged_intervals.add(new interval(start, end));
        return merged_intervals;
    }
    public static void main(String[] args)
    {
        List<interval> input = new ArrayList<interval>();
        input.add(new interval(1,4));
        input.add(new interval(2,5));
        input.add(new interval(7,9));
        System.out.print("merged intervals: ");
        for(interval interval_ : merge_intervals.merge(input))
            System.out.print("[" + interval_.start + "," + interval_.end + "] ");
        System.out.println();
        
        input = new ArrayList<interval>();
        input.add(new interval(6,7));
        input.add(new interval(2,4));
        input.add(new interval(5,9));
        System.out.print("merged intervals: ");
        for(interval interval_ : merge_intervals.merge(input))
            System.out.print("[" + interval_.start + "," + interval_.end + "] ");
        System.out.println();

        input = new ArrayList<interval>();
        input.add(new interval(1,4));
        input.add(new interval(2,6));
        input.add(new interval(3,5));
        System.out.print("merged intervals: ");
        for(interval interval_ : merge_intervals.merge(input))
            System.out.print("[" + interval_.start + "," + interval_.end + "] ");
        System.out.println();
    }
}
