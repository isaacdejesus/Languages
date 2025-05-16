class MinStack {
    a_stack: number[] = [];
    min_stack: number[] = [];
    constructor() {
        this.a_stack = [];
        this.min_stack = [];
    }

    push(val: number): void {
        this.a_stack.push(val);
        let new_min = 0;
        if(this.min_stack.length > 0)
            new_min = Math.min(val, this.min_stack[this.min_stack.length - 1])
        else 
            new_min = val;
        this.min_stack.push(new_min);
    }

    pop(): void {
        this.a_stack.pop();
        this.min_stack.pop();
    }

    top(): number {
        return this.a_stack[this.a_stack.length - 1];

    }

    getMin(): number {
        return this.min_stack[this.min_stack.length - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */