const fs = require('fs');
const path = require('path');

const rawInput = fs.readFileSync(path.join(__dirname, 'input.txt'), 'utf8');
const lines = rawInput.split('\n');

const arr1 = [];
const count = new Map();

for (const line of lines) {
    const vals = line.trim().split(/\s+/g);
    if (vals.length === 2) {
        arr1.push(parseInt(vals[0]));

        const num = parseInt(vals[1]);
        count.set(num, (count.get(num) || 0) + 1);
    }
}

let sum = 0;
for (let i = 0; i < arr1.length; i++) {
    sum += arr1[i] * (count.get(arr1[i]) || 0);
}

console.log(sum);
