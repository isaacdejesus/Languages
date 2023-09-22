const isBadVersion = (n: number): boolean => {
    return true;
}

const firstBadVersion = (n: number): number => {
    let left: number = 0;
    let right: number = n;
    while(left <= right)
    {
        let mid = Math.floor((left + right)/2);
        if(isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;
        else if(isBadVersion(mid) && isBadVersion(mid - 1))
            right = mid - 1;
        else if(!isBadVersion(mid))
            left = mid + 1;
    }
    return -1;
}