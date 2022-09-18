//Case sensitive and string must be within ""
Console.WriteLine("Hello, World!");
Console.Write("This is how ");
Console.Write(" to write all ");
Console.Write(" in a single line");
/*Console is a class
Write and WriteLine are methods of the Console class
the . is the member access operator and ; is the end statement operator
*/

//literal - Hardcoded value
//String literal
Console.WriteLine("I am a string literal");
//Char literals enclose a single alphanumeric value in ''
Console.WriteLine('x');

//Int literal outputs whole number
Console.WriteLine(123);

//Decimal literal use m or M  use m or M. Without it value is treated like a double.
Console.WriteLine(14.32m);
Console.WriteLine(14.32);

//Bool literal 
Console.WriteLine(true);

//Variables  types: string, char, int, decimal, bool
string firstName = "Isaac"; //declares a viriable of type string
Console.WriteLine(firstName);

//var can be used when assigning a value to variable. Compiler infers data type from value used to ini the var
//once ini the data type can't be changed
//var must be ini
var message = "Hello there"; //message has been assigned the string data type
Console.WriteLine(message);
//Since it is a string we can't assign it a different value type
// message = "282" //would return an error
string name = "Bob";
int msg = 3;
decimal temp = 34.4m;
Console.Write("Hello ");
Console.Write(name);
Console.Write(msg);
Console.Write(temp);

//Character escape sequences begin with \ and are followed by a char
// \t tab
// \n new line
Console.WriteLine("Hello\nWorld!");
// \" can be used to escape and wrap a word in "" within a string literal
Console.WriteLine("Hello \"World\"!");
// use \\ to escape or be able to print a single \ within a string literal
Console.WriteLine("c:\\source\\repos");
//Longer escaping example
Console.WriteLine("Generating invoices for customer \"ABC Corp\" ...\n");
Console.WriteLine("Invoice: 1021\t\tComplete!");
Console.WriteLine("Invoice: 1022\t\tComplete!");
Console.WriteLine("\nOutput Directory:\t");

//verbatim string literal use @"content"
//verbatim literal allows to keep whitespace and not need to escape chars
Console.WriteLine(@"   c:\source\repos   
              (""this is where your code goes"")");
//escaping unicode use \u followed by 4 unicode chars
// Kon'nichiwa World
 Console.WriteLine("\u3053\u3093\u306B\u3061\u306F World!");

 //string concat
 string greeting = "Hello";
 Console.WriteLine(greeting + " " + firstName + "!");

 //string interpolation allows combination of string literal and variables 
 string newMsg = $"Hello {firstName}!";
 Console.WriteLine(newMsg);
//combining verbating literals with string interpolation 
string projectname = "First-Project";
Console.WriteLine($@"C:\Output\{projectname}\Data");
//more complex example
string projectName = "ACME";
string englishLocation = $@"c:\Exercise\{projectName}\data.txt";
Console.WriteLine($"View English output:\n\t\t{englishLocation}\n");
            
string russianMessage = "\u041f\u043e\u0441\u043c\u043e\u0442\u0440\u0435\u0442\u044c \u0440\u0443\u0441\u0441\u043a\u0438\u0439 \u0432\u044b\u0432\u043e\u0434";
string russianLocation = $@"c:\Exercise\{projectName}\ru-RU\data.txt";
Console.WriteLine($"{russianMessage}:\n\t\t{russianLocation}\n");

//adding numbers
Console.WriteLine(9 + 3);
//Mixing data types causes implicit type conversion
//Here, Int is converted to a string in order to concat to the rest of the string
//We need () around (widgetsSold + 7) so that it adds 7 + 7, 
//Without(), it adds them like string resulting in 77
int widgetsSold = 7;
Console.WriteLine(firstName + " sold " + (widgetsSold + 7) + " widgets.");
//arithmetic operators: +, -, * , /
//Division will return int if both operants are ints and data type is int
//in order to get decimals, data type must be decimal and data type of one or both operands must be decimal type
decimal decimalQuotient = 7.0m/5;
Console.WriteLine(decimalQuotient);
//casting ints to decimals
int first = 7;
int second = 5;
decimal quotient = (decimal)first / (decimal)second;
Console.WriteLine(quotient);
//remainder operator % returns remainder of int division
Console.WriteLine("Modulus of 200 / 5 : " + (200 % 5));
Console.WriteLine("Modulus of 7 / 5 : " + (7 % 5));

//++, +=, -=, *=,  and -- operators
int value = 0;
value = value + 5;
value +=5;  //same as above
value = value + 1;
value++;  //same as above

Console.WriteLine(Math.Max(first, second));


//booleans operators ==, >, <, >=, <=
//Example using if else, boolean logic and random object
//Start of roll dice example
Random dice = new Random();

int roll1 = dice.Next(1, 7);
int roll2 = dice.Next(1, 7);
int roll3 = dice.Next(1, 7);

int total = roll1 + roll2 + roll3;

Console.WriteLine($"Dice roll: {roll1} + {roll2} + {roll3} = {total}");

if ((roll1 == roll2) || (roll2 == roll3) || (roll1 == roll3))
{
        if ((roll1 == roll2) && (roll2 == roll3))
        {
                    Console.WriteLine("You rolled triples!  +6 bonus to total!");
                            total += 6;
        }
            else
            {
                        Console.WriteLine("You rolled doubles!  +2 bonus to total!");
                                total += 2;
            }
}
if (total >= 16)
        Console.WriteLine("You win a new car!");
else if (total >= 10)
        Console.WriteLine("You win a new laptop!");
else if (total == 7)
        Console.WriteLine("You win a trip for two!");
else
        Console.WriteLine("You win a kitten!");
//end of roll dice example

//start of arrays and iteration
string[] fraudulentOrderIDs = new string[3];
//assign values
fraudulentOrderIDs[0] = "A123";
fraudulentOrderIDs[1] = "B456";
fraudulentOrderIDs[2] = "C789";
//attempting to assign value to [3] throw out of range error
//Retrieving data from arrays
Console.WriteLine($"First: {fraudulentOrderIDs[0]}");
Console.WriteLine($"Second: {fraudulentOrderIDs[1]}");
Console.WriteLine($"Third: {fraudulentOrderIDs[2]}");
//ini array at declaration time
char[] charArr = {'a', 'b', 'c'};
//Length return size of arr
Console.WriteLine($"Size of character array is: {charArr.Length}");
//foreach to iterate through arr
int[] inventory = { 200, 450, 700, 175, 250  };
int sum = 0;
int bin = 0;
foreach (int items in inventory)
{
        sum += items;
        bin++;
        Console.WriteLine($"Bin {bin} = {items} items (Running total: {sum})");
}
Console.WriteLine($"We have {sum} items in inventory.");

string[] orderIDs = { "B123", "C234", "A345", "C15", "B177", "G3003", "C235", "B179"  };
foreach (string orderID in orderIDs)
{
        if (orderID.StartsWith("B"))
                    Console.WriteLine(orderID);
}
