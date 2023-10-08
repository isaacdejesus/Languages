class MyStack {
    q1: number[] = [];
    q2: number[] = [];
    constructor() {
        this.q1 = [];
        this.q2 = [];
    }

    push(x: number): void {
        while(this.q1.length > 0)
        {
            this.q2.push(this.q1[0]);
            this.q1.shift();
        }
        this.q1.push(x);
        while(this.q2.length > 0)
        {
           this.q1.push(this.q2[0]);
           this.q2.shift();
        }
    }

    pop(): number {
        let val = this.q1[0];
        this.q1.shift();
        return val;
    }

    top(): number {
        return this.q1[0];
    }

    empty(): boolean {
        return this.q1.length < 1;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */