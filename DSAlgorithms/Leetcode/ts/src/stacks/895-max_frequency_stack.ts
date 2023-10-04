class FreqStack {
    max_count: number;
    val_count;
    stacks_hash;
    constructor() {
        this.max_count = 0
        this.val_count = new Map<number, number>();
        this.stacks_hash = new Map<number, number[]>();
    }

    push(val: number): void {
        let current_val_count= 0;
        if(this.val_count.has(val))
            current_val_count = this.val_count.get(val) + 1;
        else
            current_val_count = 1;
        this.val_count.set(val, current_val_count);
        if(current_val_count > this.max_count)
        {
            this.max_count = current_val_count;
            const temp_stack: number[] = [];
            this.stacks_hash.set(current_val_count, temp_stack);
        }
        let temp_stack: number[] = this.stacks_hash.get(current_val_count);
        temp_stack.push(val);
        this.stacks_hash.set(current_val_count, temp_stack);
    }

    pop(): number {
        const temp: number[] = this.stacks_hash.get(this.max_count);
        //this.stacks_hash.get(this.max_count);
        
        let result = 0;
        if(temp.length > 0)
        {
            result = temp[temp.length - 1];
            temp.pop();
            this.stacks_hash.set(this.max_count, temp);
            if(this.val_count.has(result))
            {
                let current = this.val_count.get(result);
                this.val_count.set(result, current - 1);
            }
            if(temp.length < 1)
                this.max_count--;
        } 
        return result;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * var obj = new FreqStack()
 * obj.push(val)
 * var param_2 = obj.pop()
 */