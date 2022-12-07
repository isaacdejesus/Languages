const floodFill = (image: number[][], sr: number, sc: number, color: number): number[][] =>{
    if(image[sr][sc] !== color)
        DFS(image, sr, sc, color, image[sr][sc]);
    return image;
};

const DFS = (image: number[][], sr: number, sc: number, color: number, oldColor: number): number[][] => {
    if(image[sr]?.[sc] === oldColor)
        {
            image[sr][sc] = color;
            DFS(image, sr + 1, sc, color, oldColor);
            DFS(image, sr - 1, sc, color, oldColor);
            DFS(image, sr , sc + 1, color, oldColor);
            DFS(image, sr , sc - 1, color, oldColor);
        }
    return image;
}