class Queue{
       stack_in: number[] = [];
       stack_out: number[] = [];
    constructor() {}
    push(x: number): void {
        this.stack_in.push(x);
    }
    pop(): number {
        this.peek();
        const valueToPop = this.stack_out[this.stack_out.length - 1];
        this.stack_out.pop();
        return valueToPop;
    }
    peek(): number {
        if(this.stack_out.length === 0)
            while(this.stack_in.length !==0)
            {
                this.stack_out.push(this.stack_in[this.stack_in.length - 1]);
                this.stack_in.pop();
            }
            return this.stack_out[this.stack_out.length - 1];
    }
    empty(): boolean {
        return (this.stack_in.length === 0 && this.stack_out.length === 0)
    }
}