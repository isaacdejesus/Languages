public class dvd {
    public String name;
    public int release_year;
    public String director;

    public dvd(String name, int release_year, String director){
        this.name = name;
        this.release_year = release_year;
        this.director = director;
    }
    public String toString() {
        return this.name + ", directed by " + this.director + ", released in " + this.release_year;        
    }
    public static void main(String[] args)
    {
        //creates array of dvd object type
        dvd[] dvd_collection = new dvd[15];
        //creates an object of type dvd
        dvd avengers_dvd = new dvd("The avengers", 2012, "Joss Whedon");
        //insert avengers_dvd object into 7th index
        dvd_collection[7] = avengers_dvd;
        //create and insert more dvd type objects to dvd type arr
        dvd incredibles_dvd = new dvd("The incredibles", 2004, "Brad Bird");
        dvd findingdory_dvd = new dvd("Finding Dory", 2016, "Andrew Stanton");
        dvd lionking_dvd = new dvd("The Lion King", 2019, "Jon Favreau");
        dvd_collection[3] = incredibles_dvd;
        dvd_collection[9] = findingdory_dvd;
        dvd_collection[2] = lionking_dvd;
        //accessing items from arr
        System.out.println(dvd_collection[7]);

        
    }
}
