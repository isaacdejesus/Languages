interface ChildProps {
    color: string;
    onClick: () => void;
};

export const Child = ({ color, onClick}: ChildProps) => {
    return (
        <div>
            {color}
            <button onClick={onClick}> Click me </button>
        </div>
    )
};
//same as Child, just diff way to passing props/types
export const ChildAsFC: React.FC<ChildProps> = ({color, onClick}) => {
    return (
        <div> 
            {color} 
            <button onClick={onClick}> Click me </button>
        </div>
    )
}
