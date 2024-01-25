
let John = {name: "John doee"},
    Lily = {name: "Lily Bush"},
    Peter = {name: "Peter Druck"}

//create empty map
let userRoles = new Map();

//add elements to map
userRoles.set(John, 'admin');

//can also initialize map with iterable object
let userRoles2 = new Map([
    [John, 'admin'],
    [Lily, 'editor'],
    [Peter, 'subscriber']
]);

//get elements from map by Key  
//returns undefined if not found
console.log(userRoles2.get(Peter));

//check existance of element by key
console.log(userRoles2.has(Peter));

//get number os elements in map
console.log(userRoles2.size);

//iterate over map keys
//keys() returns iterator object containing keys of elements in map
for(const user of userRoles2.keys())
    console.log(user.name);

//iterate over map values
for(const role of userRoles2.values())
    console.log(role);

//iterate to obtain array of key/value
for(const role of userRoles2.entries())
    console.log(`${role[0].name}: ${role[1]}`);
//iterate by deconstructuring
for(let [user, role] of userRoles2.entries())
    console.log(`${user.name}: ${role}`);
//use forEach to iterate
userRoles2.forEach((role, user) => console.log(`${user.name}: ${role}`));
//converting keys into an array of keys
const keys = [...userRoles2.keys()];
console.log(keys);
//converting vlaues into array os keys
const roles = [...userRoles2.values()];
console.log(roles);
//delete by key
userRoles2.delete(Peter);
//delete all entries in map
userRoles2.clear();
