class HashTable {
    data: any[]
    constructor(size: number){
        this.data = new Array(size);
    }
    _hash(key: string) {
        let hash = 0;
        for(let  i = 0; i < key.length; i++){
            hash = (hash + key.charCodeAt(i) * i) % this.data.length;
        }
        return hash;
    }
    set(key: string, value: string){
        let address = this._hash(key);
        if(!this.data[address]){
            this.data[address] = [];
            this.data[address].push([key, value])
        }
    }
}
const myHash = new HashTable(50);
myHash._hash('mebh');
