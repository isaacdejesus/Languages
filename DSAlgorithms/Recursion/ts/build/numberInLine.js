"use strict";
const numberInLine = (num) => {
    if (num <= 1)
        return 1;
    return numberInLine(num - 1) + 1;
};
console.log(numberInLine(5));
