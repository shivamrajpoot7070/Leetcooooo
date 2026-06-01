/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var filteredIndex = 0;
    for (var i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {
            if (i !== filteredIndex) {
                // now I will Swap current element with next available position in filtered array
                var temp = arr[i];
                arr[i] = arr[filteredIndex];
                arr[filteredIndex] = temp;
            }
            filteredIndex++;
        }
    }
    // then we can Remove the remaining elements after filteredIndex
    arr.length = filteredIndex;
    return arr;
};