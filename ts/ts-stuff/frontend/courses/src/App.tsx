import Header from './components/Header'
import Content from './components/Content'
import Total from './components/Total'
import {contentFormat, CoursePart} from './types'
const App = () => {
  const courseName = "Half Stack application development";
  const courseParts: CoursePart[] = [
    {
        name: "Fundamentals",
        exerciseCount: 10,
        description: "This is the leisured course part",
        type: "normal"
    },
    {
        name: "Advanced",
        exerciseCount: 7,
        description: "This is the harded course part",
        type: "normal"
    },
    {
        name: "using props to pass data",
        exerciseCount: 7,
        groupProjectCount: 3,
        type: "groupProject"

    },
    {
      name: "Deeper type usage",
      exerciseCount: 14,
        description: "Confusing description",
        exerciseSubmissionLink: "https://blah.wjwh.com",
        type: "submission"
    }
  ];

  return (
    <div>
      <Header courseName = {courseName}/>
      <Content data={courseParts}/>
      <Total data={courseParts}/>
    </div>
  );
};

export default App;
