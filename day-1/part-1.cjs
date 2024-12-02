const fs = require('fs');
const path = require('path');

const rawInput = fs.readFileSync(path.join(__dirname, 'input.txt'), 'utf8');
const lines = rawInput.split('\n');

const arr1 = [];
const arr2 = [];
for (const line of lines) {
    const vals = line.trim().split(/\s+/g);
    if (vals.length === 2) {
        arr1.push(parseInt(vals[0]));
        arr2.push(parseInt(vals[1]));
    }
}

arr1.sort((a, b) => a - b);
arr2.sort((a, b) => a - b);

let sum = 0;
for(let i = 0; i < arr1.length; i++) {
    sum += Math.abs(arr1[i] - arr2[i]);
}

console.log(sum);
