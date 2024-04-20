import {Sorter} from './Sorter';
export class NumbersCollection extends Sorter{
    constructor(public data: number[]) {
        super();
    }    
    //allows us to call length like a property instead of a method.
    //can just do collection.length instead of collection.length()
    get length() : number {
        return this.data.length;
    }
    compare(leftIndex: number, rightIndex: number): boolean {
        return this.data[leftIndex] > this.data[rightIndex];
    }
    swap(leftIndex: number, rightIndex: number): void {
        const leftHand = this.data[leftIndex];
        this.data[leftIndex] = this.data[rightIndex];
        this.data[rightIndex] = leftHand;
    }
}
