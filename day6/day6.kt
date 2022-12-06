import java.io.File

fun main() {
	part1()
	part2()
}

fun part2() {
	val file = File("input.txt")
		.inputStream()
		.readBytes()
		.toString(Charsets.UTF_8)

	val buffer = arrayListOf<Char>()

	for (i in file.indices) {
		if (buffer.count() < 14) {
			buffer.add(file[i])
		} else {
			val set = mutableSetOf<Char>()

			for (j in buffer) {
				set.add(j);
			}

			if (set.count() == 14) {
				println("PART 2: " + i)
				break
			}

			buffer.removeAt(0)
			buffer.add(file[i])
		}
	}
}

fun part1() {
	val file = File("input.txt")
		.inputStream()
		.readBytes()
		.toString(Charsets.UTF_8)

	val buffer = arrayListOf<Char>()

	for (i in file.indices) {
		if (buffer.count() < 4) {
			buffer.add(file[i])
		} else {
			val set = mutableSetOf<Char>()

			for (j in buffer) {
				set.add(j);
			}

			if (set.count() == 4) {
				println("PART 1: " + i)
				break
			}

			buffer.removeAt(0)
			buffer.add(file[i])
		}
	}
}
