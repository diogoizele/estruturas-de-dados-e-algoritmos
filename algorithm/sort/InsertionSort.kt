package algorithm.sort

object Solution {

  fun insertionSort(array: Array<Int>): Array<Int> {

    for (j in 1 until array.size) {
      val temp = array[j]
      var i = j - 1

      while (i >= 0 && array[i] > temp) {
        array[i + 1] = array[i]
        i--
      }

      array[i + 1] = temp
    }

    return array
  }
}

fun main() {
  val array = Solution.insertionSort(arrayOf(3, 8, 1, 6, 5, 2, 9, 7, 4))

  for (element in array) {
    print("$element, ")
  }
  print("\n")
}
