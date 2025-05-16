/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */


 const guessNumber = (n: number): number =>{
    let left = 1;
    let right = n;
    while(true)
    {
       let mid = Math.floor(left + (right - left ) / 2);
       let pick = guess(mid);
       if(pick === 0)
           return mid;
       if(pick > 0)
           left = mid + 1;
       else
           right = mid - 1;
    }


};