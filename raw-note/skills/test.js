// async function bfunc() {
//   console.log("2 - b func")
// }

// async function afunc() {
//   await bfunc() // rest of function pushed to event queue
//   console.log("4 - a func")
// }

// const prom = new Promise((resolve, reject) => {
//   console.log("1 - inside promise")
//   resolve("5 - foo")
//   afunc()
// }).then((value) => {
//   // this is also pushed to the event queue
//   console.log(value)
// })

// console.log("3 - last thing")

// Please finish the below questions below, meant to be simple questions, please state any assumption instead of asking questions if you are unsure of anything

// 1. Write a function that concatenates two lists. [a,b,c], [1,2,3] → [a,b,c,1,2,3]

const concatArrays = (...arrays) => {
  if (!Array.isArray(arrays)) return
  const isAllArrays = arrays.every(Array.isArray)
  if (!isAllArrays) return

  return [].concat(...arrays)
}

console.log('concatArrays', concatArrays(["a", "b", "c"], [1, 2, 3]))
console.log('concatArrays', concatArrays(["a", ["b", "c"]], [1, 2, 3]))

// 2. Write a function that combines two lists by alternatingly taking elements, e.g. [a,b,c], [1,2,3] → [a,1,b,2,c,3].

const switchCombine = (...arrays) => {
  if (!Array.isArray(arrays)) return
  if (!arrays.every(Array.isArray)) return

  const result = []
  let roundRobin = arrays.map(
    (array) =>
      (function* () {
        for (const element of array) {
          yield element
        }
      })()
  )
  while (roundRobin.length > 0) {
    let nextRound = []
    for (const arrayGenerator of roundRobin) {
      const { value, done } = arrayGenerator.next()
      if (!done) {
        result.push(value)
        nextRound.push(arrayGenerator)
      }
    }
    roundRobin = nextRound
  }
  return result
}

console.log('switchCombine', switchCombine(["a", "b", "c"], [1, 2, 3]))
console.log('switchCombine', switchCombine(["a", "b", "c"], [1, 2, 3, 4, 5]))
console.log('switchCombine', switchCombine(["a", "b", "c", 'd', 'e'], [1, 2, 3]))

// 3. Write a function that merges two sorted lists into a new sorted list. [1,4,6],[2,3,5] → [1,2,3,4,5,6]. You can do this quicker than concatenating them followed by a sort.

const mergeSorted = (array1, array2) => {
  const sortedResult = []
  let index1 = 0
  let index2 = 0
  while (index1 < array1.length && index2 < array2.length) {
    const element1 = array1[index1]
    const element2 = array2[index2]
    if (element1 <= element2) {
      sortedResult.push(element1)
      index1++
    } else {
      sortedResult.push(element2)
      index2++
    }
  }
  while (index1 < array1.length) {
    sortedResult.push(array1[index1])
    index1++
  }
  while (index2 < array2.length) {
    sortedResult.push(array2[index2])
    index2++
  }
  return sortedResult
}

console.log('mergeSorted', mergeSorted([1,4,6], [2,3,5]))

// 4. Write function that translates a text to Pig Latin. 
// English is translated to Pig Latin by taking the first letter of every word, 
// moving it to the end of the word and adding 'ay'. 
// "The quick brown fox" becomes "Hetay uickqay rownbay oxfay".

const pigLatinize = (originString) => {
  // Assume that the origin string contains only [a-zA-Z] and space
  const words = originString.split(' ')
  return words.map(word => {
    const rotateAndKeepFormat = word.split('').map((letter, index, word) => {
      const nextIndex = (index + 1) % word.length
      if (/[A-Z]/.test(letter)) {
        return word[nextIndex].toUpperCase()
      } else {
        return word[nextIndex].toLowerCase()
      }
    }).join('')

    if (rotateAndKeepFormat === '') return 
    
    return rotateAndKeepFormat.concat('ay')
  }).join(' ')
}

console.log('pigLatinize', pigLatinize("The quick brown   fox"))
