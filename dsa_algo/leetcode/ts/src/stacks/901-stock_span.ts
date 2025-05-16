class StockSpanner {
    price_stack: number[] = [];
    span_stack: number[] = [];
    constructor() {
        this.price_stack = [];
        this.span_stack = [];
    }

    next(price: number): number {
        let span = 1;
        while(this.price_stack.length > 0 && this.price_stack[this.price_stack.length - 1] <= price)
        {
            span += this.span_stack[this.span_stack.length - 1];
            this.span_stack.pop();
            this.price_stack.pop();
        }
        this.price_stack.push(price);
        this.span_stack.push(span);
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */