export const dateStringToDate = (dateString: string): Date => {
    //ex 28/10/2018 becomes ['28', '10', '2019']
    const dateParts = dateString
        .split('/')
        .map((value: string): number => {
            return parseInt(value);
        });
    return new Date(dateParts[2], dateParts[1] - 1, dateParts[0]);
};
