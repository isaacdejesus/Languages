const numbers2: number[] = [1, 2, 3, 4, 5];
//reduce takes two parameters a fn and an optional initial value.
//Here, we set ini value to 0
//reduce calls the fn function for each element. 
//resulting into a single return value
const sum: number = numbers2.reduce((prev: number, curr: number) => prev + curr, 0 );
console.log(sum);

//a more complex example
interface Cart {
    product: string
    qty: number
    price: number
}
const shoppingCart: Cart[]  = [
    {
        product: 'phone',
        qty: 1,
        price: 500
    },
    {
        product: 'Screen Protector',
        qty: 1,
        price: 10
    },
    {
        product: 'Memory card',
        qty: 2,
        price: 20
    }
];

const total2 = shoppingCart.reduce((prev: number, curr:Cart) => prev + curr.qty * curr.price, 0 )
console.log(total2);

type Order = {
    amount: number
}

const orders = [
    { amount: 250 },
    { amount: 400 },
    { amount: 100 },
    { amount: 325 },
];

const totalAmount: number = orders.reduce((sum: number, order: Order) => sum + order.amount, 0);
console.log(totalAmount);
