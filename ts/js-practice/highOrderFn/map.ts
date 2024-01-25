const numbers: number[] = [10, 20, 30, 40, 50];
//map takes a function and maps each value in array to fn and returns new array
//containing new values
const sqNumbers= numbers.map((num: number) => num * num);
console.log(numbers);
console.log(sqNumbers);

interface Animal {
    name: string;
    species: string;
};
const animals2: Animal[] = [
    {name: 'Fluch', species: 'rabbit'},
    {name: 'Caroij', species: 'dog'},
    {name: 'Hamilton', species: 'dog'},
    {name: 'Harold', species: 'fish'},
    {name: 'Ursula', species: 'cat'},
    {name: 'Jimmy', species: 'fish'}
];

const animalNames: string[] = animals2.map((animal: Animal) => animal.name + ' is a' + animal.species);
console.log(animalNames);
