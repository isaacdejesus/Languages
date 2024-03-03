import {CoursePart} from '../types'
const Part = ({coursePart}:{coursePart: CoursePart} ): JSX.Element => {
    const assertNever = (value: never): never => {
        throw new Error(
            `unhandled union member: ${JSON.stringify(value)}`
        );
    };
    const courseType = (course: CoursePart): JSX.Element =>{
            switch(course.type){
                case "normal":
                    return(
                    <div>
                        <p>
                        {course.name} {course.exerciseCount}
                        <br />
                        <i>{course.description} </i>
                        </p>
                    </div>)
                    break;
                case "groupProject":
                    return(
                    <div>
                        <p>{course.name} {course.exerciseCount}
                        <br />
                        <i>Group projects {course.groupProjectCount}</i>
                        </p>
                    </div>)
                    break;
                case "submission":
                    return(
                    <div>
                        <p>{course.name} {course.exerciseCount}
                        <br />
                        <i>{course.description}</i>
                        <br />
                        <i> Submit to {course.exerciseSubmissionLink}</i>
                        </p>
                    </div>)
                    break;
                default:
                    return assertNever(course)
                    break;
            }
    }
    return (
        <div>
        {courseType(coursePart)}
        </div>
    )
}
export default Part
