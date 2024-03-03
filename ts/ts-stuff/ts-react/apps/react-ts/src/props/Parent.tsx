import { Child } from './Child';
const Parent = () => {
    return <Child color="green" onClick={()=> console.log('clicked')}/>
};

export default Parent;
