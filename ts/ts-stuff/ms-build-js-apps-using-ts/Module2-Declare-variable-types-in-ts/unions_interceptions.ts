//Union type accepts||
//dif types but restricts only to types defined for union
let multi_type: number | boolean;
multi_type = 20;        //valid
multi_type = true;      //valid
//multi_type = "hello";   //invalid

//Ex using type guards
function add(x: number | string, y: number | string){
    if(typeof x == 'number' && typeof y === 'number')
        return x + y;
    if(typeof x == 'string' && typeof y === 'string')
        return x.concat(y);
    throw new Error('Parameters must be numbers or strings')
}

//interception types &
//combined 2+ types to create new type that has all properties of existing types
//Most often used with interfaces
interface Employee {
    employee_id: number;
    age: number;
}
interface Manager {
    stock_plan: boolean;
}
type management_employee = Employee & Manager;
let new_manager: management_employee = {
    employee_id: 12345,
    age: 34,
    stock_plan: true
};

//literal types
