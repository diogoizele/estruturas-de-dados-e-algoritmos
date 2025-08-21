package algorithm.merge

object Solution {
  fun merge(arr1: IntArray, arr2: IntArray, tam1: Int, tam2: Int): IntArray {
    var i = 0
    var j = 0
    var k = 0
    val result: IntArray = IntArray(tam1 + tam2)

    while (i < tam1 && j < tam2) {
      if (arr1[i] < arr2[j]) {
        result[k++] = arr1[i++]
      } else {
        result[k++] = arr2[j++]
      }
    }

    while (j < tam2) result[k++] = arr2[j++]
    while (i < tam1) result[k++] = arr1[i++]

    return result
  }

  fun mergeSubArray(array: IntArray, p: Int, q: Int, r: Int) {
    val size = r - p
    val aux = IntArray(size)

    var i = p
    var j = q + 1
    var k = 0

    while (i < q && j < r) {
      if (array[i] < array[j]) {
        aux[k++] = array[i++]
      } else {
        aux[k++] = array[j++]
      }
    }

    while (i < q) aux[k++] = array[i++]
    while (j < r) aux[k++] = array[j++]

    k = 0
    for (l in p until r) {
      array[l] = aux[k++]
    }
  }
}

fun main() {

  val array1 = intArrayOf(1, 2, 4, 6, 9)
  val array2 = intArrayOf(3, 5, 6, 8)

  val result = Solution.merge(array1, array2, array1.size, array2.size)

  print("Merge: ")
  for (el in result) {
    print("$el, ")
  }
  print("\n")

  val array3 = intArrayOf(1, 2, 4, 6, 9, 3, 5, 6, 8)
  Solution.mergeSubArray(array3, 0, array3.size / 2, array3.size)

  print("\nMerge sub-array: ")
  for (el in array3) {
    print("$el, ")
  }
  print("\n")
}
