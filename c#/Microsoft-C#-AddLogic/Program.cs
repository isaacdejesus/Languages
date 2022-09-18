//equality operator ==
Console.WriteLine("a" == "A");
//ToUpper(), ToLower(), Trim() removes blanks spaces around string
string value1 = " a";
string value2 = "A ";
Console.WriteLine(value1.Trim().ToLower() == value2.Trim().ToLower());
//inequality operator !=
Console.WriteLine("a" != "a");
//comparison operators >, <, >=, <=
//Logical Negation
string pangram = "The quick brown fox jumps over the lazy dog.";
Console.WriteLine(pangram.Contains("fox") == false);
Console.WriteLine(!pangram.Contains("fox"));

//conditional operator
int saleAmount = 1001;
Console.WriteLine($"Discount: {(saleAmount > 1000 ? 100: 50)}");
//another conditional op example
Random coin = new Random();
Console.WriteLine((coin.Next(0, 2) == 0) ? "heads" : "tails");
//see Classes.cs file for example of using different namespaces, classes and methods
//Switch
int employeeLevel = 100;
string employeeName = "John Smith";
string title = "";
switch (employeeLevel)
{
        case 100:
        case 200:
            title = "Senior Associate";
            break;
        case 300:
            title = "Manager";
            break;
        case 400:
            title = "Senior Manager";
            break;
        default:
            title = "Associate";
            break;
}
Console.WriteLine($"{employeeName}, {title}");
//end switch

//for loop
string[] names = {"Alex", "Eddie", "David", "Michael"};
for(int i = 0; i< names.Length; i++)
    if(names[i] == "David")
        names[i] = "Sam";
foreach(var name in names) 
    Console.WriteLine(name);

//fizzbuzz
for (int i = 1; i < 101; i++)
{
    if ((i % 3 == 0) && (i % 5 == 0))
        Console.WriteLine($"{i} - FizzBuzz");
    else if (i % 3 == 0)
        Console.WriteLine($"{i} - Fizz");
    else if (i % 5 == 0)
        Console.WriteLine($"{i} - Buzz");
    else
        Console.WriteLine($"{i}");
}

//do while and while
Random random = new Random();
int current = random.Next(1, 11);
do
{
    current = random.Next(1, 11);
    if(current >= 8)
        continue;
    Console.WriteLine(current);
}
while(current !=7);
