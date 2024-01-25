const items = [10, 20, 30, 40];
let total = 0;
for(const item in items) {
    total += items[item];
}
console.log(total);
//item is the index
for(const item in items)
    console.log(item);

