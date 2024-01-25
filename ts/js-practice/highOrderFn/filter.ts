//filter is a function on array that takes function as argument to 
//return a new filtered version of the array
interface Animal {
    name: string;
    species: string;
};
const animals: Animal[] = [
    {name: 'Fluch', species: 'rabbit'},
    {name: 'Caroij', species: 'dog'},
    {name: 'Hamilton', species: 'dog'},
    {name: 'Harold', species: 'fish'},
    {name: 'Ursula', species: 'cat'},
    {name: 'Jimmy', species: 'fish'}
];
const dogs: Animal[] = animals.filter((animal: Animal) => animal.species === 'dog');
console.log(dogs);
interface City {
    name: string
    population: number
}

const cities: City[] = [
    {name: "Los Angeles", population: 3434340000},
    {name: "New York", population: 343848},
    {name: "Chicago", population: 388999},
    {name: "Houston", population: 209248},
    {name: "Philadelphia", population: 9999903843}
];
//filter takes a function, passes each element to function and
//returns new array with values that pass the test.
//In this case, if population > 3m
const bigCities: City[]= cities.filter((city : City) => city.population > 3000000);
console.log(bigCities);

//since result is another array, we can chain sort or map. 
cities
    .filter((city: City) => city.population < 3000000)
    .sort((c1: City, c2: City) => c1.population - c2.population)
    .map((city: City) => console.log(city.name + ':' + city.population));

