//Interface - creates a new type, describing properties of an object/type
interface Vehicle {
    name: string;
    year: number;
    broken: boolean
    summary(): string; //function that returns a string
} 
const oldCivic = {
    name: 'civic',
    year: 2000,
    broken: true,
    summary(): string {
        return `Name: ${this.name}`;
    }
};

const printVehicle = (vehicle: Vehicle): void => {
    console.log(vehicle.summary());
}
