function maxArea(height: number[]): number {
    let l = 0; 
    let r = height.length - 1;
    let res = 0;
    while( l < r) {
        let area = (r - l) * Math.min(height[l], height[r])
        res = Math.max(res, area);
        if(height[l] < height[r])
            l += 1;
        else r -= 1;
    }
    return res;
};