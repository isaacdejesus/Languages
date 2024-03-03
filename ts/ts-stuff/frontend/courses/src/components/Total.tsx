import {contentFormat} from '../types'
const Total = ({data}: {data: contentFormat[]}): JSX.Element =>{
    const totals = data.map(item => item.exerciseCount).reduce((prev, curr) => prev + curr, 0);
    return (
        <p>Number of exercises {totals}</p>
    )
}
export default Total
