//integral types and MinValue/MaxValue numeric properties
Console.WriteLine("Signed integral types:");

Console.WriteLine($"sbyte  : {sbyte.MinValue} to {sbyte.MaxValue}");
Console.WriteLine($"short  : {short.MinValue} to {short.MaxValue}");
Console.WriteLine($"int    : {int.MinValue} to {int.MaxValue}");
Console.WriteLine($"long   : {long.MinValue} to {long.MaxValue}");

Console.WriteLine("");
Console.WriteLine("Unsigned integral types:");

Console.WriteLine($"byte   : {byte.MinValue} to {byte.MaxValue}");
Console.WriteLine($"ushort : {ushort.MinValue} to {ushort.MaxValue}");
Console.WriteLine($"uint   : {uint.MinValue} to {uint.MaxValue}");
Console.WriteLine($"ulong  : {ulong.MinValue} to {ulong.MaxValue}");

//floating point types
//decimal type is stores a more accurate value compared to float and double
//decimal results in more accurate result because it uses more memory
Console.WriteLine("");
Console.WriteLine("Floating point types:");
Console.WriteLine($"float  : {float.MinValue} to {float.MaxValue} (with ~6-9 digits of precision)");
Console.WriteLine($"double : {double.MinValue} to {double.MaxValue} (with ~15-17 digits of precision)");
Console.WriteLine($"decimal: {decimal.MinValue} to {decimal.MaxValue} (with 28-29 digits of precision)");

//reference type variables
int[] data = new int[3]; //default value of elements is 0

//data type casting and conversions
//It is always possible to cast down a a different type that uses less memory/less precision
//ex. from decimal to int
decimal myDecimal = 3.14m;
Console.WriteLine($"decimal: {myDecimal}");
int myInt = (int)myDecimal;
Console.WriteLine($"int: {myInt}");
//ToString() converts numbers to string
int first = 18;
int second = 10;
string msg = first.ToString() + second.ToString();
Console.WriteLine(msg);
//Parse() converts string to number
string First = "5";
string Second = "7";
int sum = int.Parse(First) + int.Parse(Second);
Console.WriteLine(sum);
//TryParse() use it if not sure if value can be converted to number
//Convert.ToInt32()  convers string to number
string value1 = "5";
string value2 = "7";
int result = Convert.ToInt32(value1) * Convert.ToInt32(value2);
Console.WriteLine(result);

int val1 = (int)1.5m; // casting truncates
Console.WriteLine(val1);
int val2 = Convert.ToInt32(1.5m); // converting rounds up
Console.WriteLine(val2);
//Casting is performed by surrounding datatype with() ex, (int), (decimal)...followed by value to be casted
//(int) 1.5m -> casts decimal to int
//casting results in loss of precision and truncates resulting value.
//(int) 1.5m -> 1
//convert class does not truncate, it rounds
//Convert.ToInt32(1.5) -> 2;

//TryParse() converts string to number if possible
//Returns true if successful
string val = "100";
int res = 0;
if (int.TryParse(val, out res))
        Console.WriteLine($"Measurement: {res}");
else
        Console.WriteLine("Unable to report the measurement.");

// Since it is defined outside of the if statement, 
// // it can be accessed later in your code.
 if (res > 0)
     Console.WriteLine($"Measurement (w/ offset): {50 + res}");

//Another TryParse() example
string[] values = { "12.3", "45", "ABC", "11", "DEF"  };
decimal total = 0m;
string message = "";
foreach (var value in values)
{
        decimal number;
            if (decimal.TryParse(value, out number))
                total += number;
             else
                message += value;
}
Console.WriteLine($"Message: {message}");
Console.WriteLine($"Total: {total}");

//Array methods
//Sort() and Reverse()
string[] pallets = { "B14", "A11", "B12", "A13"  };
Console.WriteLine("Sorted...");
Array.Sort(pallets);
foreach (var pallet in pallets)
    Console.WriteLine($"-- {pallet}");
Console.WriteLine("Reversed...");
Array.Reverse(pallets);
foreach (var pallet in pallets)
    Console.WriteLine($"-- {pallet}");
//Clear() and Resize()
//Clear() sets the elements to null. Elements still remain as part of array/empty pointing to null
//Resize() can be used to increase array size or decrease it and deleting elements at the end
Console.WriteLine("");
Array.Clear(pallets, 0, 2);
Console.WriteLine($"Clearing 2 ... count: {pallets.Length}");
foreach (var pallet in pallets)
    Console.WriteLine($"-- {pallet}");
Console.WriteLine("");
Array.Resize(ref pallets, 6);
Console.WriteLine($"Resizing 6 ... count: {pallets.Length}");
pallets[4] = "C01";
pallets[5] = "C02";
foreach (var pallet in pallets)
    Console.WriteLine($"-- {pallet}");
Console.WriteLine("");
Array.Resize(ref pallets, 3);
Console.WriteLine($"Resizing 3 ... count: {pallets.Length}");
foreach (var pallet in pallets)
    Console.WriteLine($"-- {pallet}");
//end of clear/resize

//ToCharArray(), Split() and Join()
//ToCharArray() creates an array out of chars of a string
//Split() creates an array out of string
//Join() creates a new string
string value3 = "abc123";
char[] valueArray = value3.ToCharArray();
Array.Reverse(valueArray);
//string result = new string(valueArray);
string Result = String.Join(",", valueArray);
Console.WriteLine(Result);
string[] items = Result.Split(',');
foreach (string item in items)
    Console.WriteLine(item);

//Reverse each word in a string
string pangram = "The quick brown fox jumps over the lazy dog";
string[] message1 = pangram.Split(' ');
string[] newMessage = new string[message1.Length];
for (int i = 0; i < message1.Length; i++)
{
        char[] letters = message1[i].ToCharArray();
        Array.Reverse(letters);
        newMessage[i] = new string(letters);
}

string result1 = String.Join(" ", newMessage);
Console.WriteLine(result1);

//IndexOf(), LastIndexOf() , IndexOfAny() and Substring()
string Message = "Find what is (inside the parentheses)";
int openingPosition = Message.IndexOf('(');
int closingPosition = Message.IndexOf(')');
openingPosition +=1;
int length = closingPosition - openingPosition;
Console.WriteLine(Message.Substring(openingPosition , length));

//Remove() and Replace()
string Data = "12345John Smith          5000  3  ";
string updatedData = Data.Remove(5, 20);
Console.WriteLine(updatedData);
string messagee = "This--is--ex-amp-le--da-ta";
messagee = messagee.Replace("--", " ");
messagee = messagee.Replace("-", "");
Console.WriteLine(messagee);
