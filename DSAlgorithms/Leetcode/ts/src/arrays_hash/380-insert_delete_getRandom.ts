class RandomizedSet {
    hash = new Map<number, number>();
    vec: number[] = [];
    constructor() {
    }

    insert(val: number): boolean {
        if(!this.hash.has(val))
        {
            this.hash.set(val, this.vec.length);
            this.vec.push(val);
            return true;
        }
        return false;
    }

    remove(val: number): boolean {
        if(this.hash.has(val))
        {
            const index: number = this.hash.get(val);
            const last_val_in_list: number = this.vec[this.vec.length - 1];
            this.vec[index] = last_val_in_list;
            this.vec.pop();
            this.hash.set(last_val_in_list, index);
            this.hash.delete(val);
            return true;
        }
        return false;
    }

    getRandom(): number {
        console.log(this.vec.length);
        return this.vec[Math.floor(Math.random() * this.vec.length)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
