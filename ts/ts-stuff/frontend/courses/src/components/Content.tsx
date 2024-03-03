import { CoursePart} from '../types'
import Part from '../components/Part'
const Content = ({data}: {data: CoursePart[]}): JSX.Element => {
    return (
        <div>
                {data.map((content: CoursePart) => 
                    <Part
                        key={content.exerciseCount}
                        coursePart={content}
                    />
                )}
        </div>
    )
}
export default Content
