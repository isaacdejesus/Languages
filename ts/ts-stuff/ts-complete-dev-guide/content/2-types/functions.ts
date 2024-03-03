const add = (a: number, b: number): number => {
    return a + b;
};

function divide(a: number, b: number): number {
    return a/b;
};

const multiply = function(a: number, b: number): number {
    return a * b;
};

const logger = (message: string): void => {
    console.log(message);
};

//never type used when expect not to reach end of function
const throwError = (message: string): never => {
    throw new Error(message);
};


