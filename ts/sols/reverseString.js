"use strict";
const reverse = (str) => {
    if (!str || str.length < 2 || typeof str !== 'string')
        return '';
    const backwards = [];
    const length = str.length - 1;
    for (let i = length; i >= 0; i--)
        backwards.push(str[i]);
    return backwards.join('');
};
const reverse2 = (str) => {
    return str.split('').reverse().join('');
};
const reverse3 = (str) => {
    return [...str].reverse().join('');
};
//test function
const log = reverse('Hello there!');
console.log(log);
