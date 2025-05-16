class NumArray {
    prefix:number[] = [];
    constructor(nums: number[]) {
        let current = 0;
        for(let i = 0; i < nums.length; i++)
        {
            current += nums[i];
            this.prefix.push(current);
        }
    }

    sumRange(left: number, right: number): number {
        console.log(this.prefix);
        const right_sum = this.prefix[right];
        const left_sum = this.prefix[left - 1] ? this.prefix[left - 1] : 0;
        return right_sum - left_sum;
    }
}
