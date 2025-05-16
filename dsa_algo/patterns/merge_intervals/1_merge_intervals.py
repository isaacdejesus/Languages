from __future__ import print_function
class interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    def print_interval(self):
        print("[" + str(self.start) + ", " + str(self.end) + "]", end ='')
def merge(intervals):
    if len(intervals) < 2:
        return intervals
    intervals.sort(key=lambda x: x.start)
    merged_intervals = []
    start = intervals[0].start
    end = intervals[0].end
    for i in range(1, len(intervals)):
        interval_ = intervals[i]
        if interval_.start <= end:
            end = max(interval_.end, end)
        else:
            merged_intervals.append(interval(start, end))
            start = interval_.start
            end = interval_.end
    merged_intervals.append(interval(start, end))
    return merged_intervals
def main():
    print("merged intervals: ", end='')
    for i in merge([interval(1,4), interval(2,5), interval(7,9)]):
        i.print_interval()
    print()
    
    print("merged intervals: ", end='')
    for i in merge([interval(6,7), interval(2,4), interval(5,9)]):
        i.print_interval()
    print()

    print("merged intervals: ", end='')
    for i in merge([interval(1,4), interval(2,6), interval(3,5)]):
        i.print_interval()
    print()

main()
