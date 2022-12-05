let lines = require("fs").readFileSync("input.txt", "utf-8")
	.split("\n")
	.filter(Boolean);

const stackDefinition = lines.slice(0, 9);
const stackMovements = lines.slice(9);

const parseStackDefinition = (stackDef) => {
	let stacks = [];

	for (let i = 0; i < stackDefinition.length - 1; i++) {
		let row = stackDefinition[i];
		for (let j = 0, k = 0; j < row.length; j+=4, k++) {
			let column = row.slice(j, j + 4)
			if (!/\w/.test(column)) continue;
			column = /\w/.exec(column)[0];
			if (stacks[k] == undefined) {
				stacks[k] = [];
				stacks[k].push(column);
			} else {
				stacks[k].push(column);
			}
		}
	}

	return stacks;
}

let stacks = parseStackDefinition(stackDefinition);

const parseInstruction = (instruction) => {
	const parsedInstruction = instruction.split(" ");

	return { 
		count: parseInt(parsedInstruction[1]), 
		from: parseInt(parsedInstruction[3]),
		to: parseInt(parsedInstruction[5])
	}
}

const instructions = stackMovements.map(parseInstruction);

const applyInstruction = (stack, instruction) => {
	for (let i = 0; i < instruction.count; i++) {
		let poppedItem = stack[instruction.from - 1].shift()
		stack[instruction.to - 1].unshift(poppedItem);
	}
}

const applyInstructionPartTwo = (stack, instruction) => {
	let tempArray = [];
	for (let i = 0; i < instruction.count; i++) {
		let poppedItem = stack[instruction.from - 1].shift()
		tempArray.push(poppedItem);
	}

	for (let i = 0; i < instruction.count; i++) {
		stack[instruction.to - 1].unshift(tempArray.pop());
	}
}


const part1 = false;
const part2 = false;
const testing = false;

if (testing) {
	console.log(stacks);
	console.log("---");
	applyInstructionPartTwo(stacks, instructions[0]);
	console.log(stacks);
}

if (part1) {
	instructions.forEach((ins) => {
		applyInstruction(stacks, ins);
	});

	for (let i = 0; i < stacks.length; i++) {
		console.log(stacks[i][0])
	}
}

if (part2) {
	stacks = parseStackDefinition(stackDefinition);
	instructions.forEach((ins) => {
		applyInstructionPartTwo(stacks, ins);
	});

	console.log("PART2 --------")
	for (let i = 0; i < stacks.length; i++) {
		console.log(stacks[i][0])
	}
}

