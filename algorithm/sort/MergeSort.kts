package algorithm.sort

import java.io.File

fun mergeSort(array: IntArray, first: Int, last: Int) {
  
  if (first >= last) {
    return
  }

  val middle = (last + first) / 2

  mergeSort(array, first, middle)
  mergeSort(array, middle + 1, last)

  val size = last - first + 1
  val tmp = IntArray(size)

  var i = first
  var j = middle + 1

  var k = 0

  while (i <= middle && j <= last) {
    if (array[i] < array[j]) tmp[k++] = array[i++]
    else tmp[k++] = array[j++]
  }

  while (i <= middle) tmp[k++] = array[i++]
  while (j <= last) tmp[k++] = array[j++]

  k = 0
  for (n in first..last) {
    array[n] = tmp[k++]
  }
}

val inputFile = File("numeros_10000.json")

val content = inputFile.readText()

val numbers: IntArray = content
  .removePrefix("[")
  .removeSuffix("]")
  .split(",")
  .map { it.trim().toInt() }
  .toIntArray()

// println(numbers.size)

mergeSort(numbers, 0, numbers.size - 1)

println(numbers.take(10_000))

