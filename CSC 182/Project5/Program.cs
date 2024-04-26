using Project5;

public delegate double ArrayAnalysisDelegate(double[] inp);

class MainClass
{
    static void Main()
    {
        double[] lis = { 1, 2, 3, 4, 5 };

        ArrayAnalysisDelegate maxDel = new ArrayAnalysisDelegate(DataAnalysis.get_max);
        ArrayAnalysisDelegate minDel = new ArrayAnalysisDelegate(DataAnalysis.get_min);
        var medDel = DataAnalysis.get_med;
        var meanDel = DataAnalysis.get_mean;
        ArrayAnalysisDelegate stdDevDel = (double[] inp) => { return  DataAnalysis.get_stddev(inp); };


        Console.WriteLine(minDel(lis));
        Console.WriteLine(maxDel(lis));
        Console.WriteLine(meanDel(lis));
        Console.WriteLine(medDel(lis));
        Console.WriteLine(stdDevDel(lis));

        Console.WriteLine("\n\n-----------------PERSON TESTING (the class, not on actual people lol)--------------------\n\n");

        FilterDelegate isChild = (Person p) => { return p.age < 18; };
        FilterDelegate nameStartsWithVowel = (Person p) =>
        {
            string[] vowels = { "A", "E", "I", "O", "U" };
            return vowels.Contains(p.name.Substring(0, 1));
        };

        FilterDelegate isPalindrome = (Person p) => {
            char[] charArray = p.name.ToCharArray();
            Array.Reverse(charArray);
            string name = new string(charArray).ToUpper();

            return p.name.ToUpper().Equals(name); 
        };


        Person p1 = new Person("Ava Blansfield", 20);
        Person p2 = new Person("Collin Blazevich", 14);
        Person p3 = new Person("Tacocat", 1000);
        Person p4 = new Person("Racecar", 20);
        Person p5 = new Person("Emily Thrasher", 10);
        Person p6 = new Person("Not sure, this doesn't fit any of the criteria", 20);

        Person[] people = { p1, p2, p3, p4, p5, p6 };

        Console.WriteLine("\n-----------------Children--------------------\n");

        Person.DisplayPeople(people, isChild);

        Console.WriteLine("\n-----------------Names that start with a vowel--------------------\n");

        Person.DisplayPeople(people, nameStartsWithVowel);

        Console.WriteLine("\n-----------------Palindrome names--------------------\n");

        Person.DisplayPeople(people, isPalindrome);
    }
} 






