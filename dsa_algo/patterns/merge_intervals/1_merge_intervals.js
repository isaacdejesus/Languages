//not working. Will fix later
class interval {
    constructor(start, end)
    {
        this.start = start;
        this.end = end;
    }
    print_interval(){
        process.stdout.write(`[${this.start}, ${this.end}]`);
    }
}
const merge = (intervals) => {
    if(intervals.length < 2)
        return intervals
    intervals.sort((a,b) => a.start - b.start);
    const merged_intervals = [];
    let start = intervals[0].start;
    let end = intervals[0].end;
    for(let i = 1; i < intervals.lenght; i++)
    {
        const interval_ = intervals[i];
        if(interval_.start <= end)
            end = Math.max(interval_.end, end)
        else
        {
            merged_intervals.push(new interval(start, end));
            start = interval_.start;
            end = interval_.end;
        }
    }
    merged_intervals.push(new interval(start, end));
    return merged_intervals;
}

process.stdout.write('merged intervals: ');
let result = merge([new interval(1,4), new interval(2,5), new interval(7,9)]);
for(let i = 0; i < result.length; i++)
    result[i].print_interval();
console.log();

process.stdout.write('merged intervals: ');
result = merge([new interval(6,7), new interval(2,4), new interval(5,9)]);
for(let i = 0; i < result.length; i++)
    result[i].print_interval();
console.log();

process.stdout.write('merged intervals: ');
result = merge([new interval(1,4), new interval(2,6), new interval(3,5)]);
for(let i = 0; i < result.length; i++)
    result[i].print_interval();
console.log();
