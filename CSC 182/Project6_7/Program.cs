using Project6_7;

class Program
{
    static void Main()
    {
        Calculator c = new Calculator();
        var calcSub = new CalculatorSubscriber("CalculatorNotifier", c);

        var addNums = (double a, double b) => c.addDoubs(a, b);
        var subNums = (double a, double b) => c.subDoubs(a, b);
        var mulNums = (double a, double b) => c.mulDoubs(a, b);
        var divNums = (double a, double b) => c.divDoubs(a, b);

        Console.WriteLine("Addition: 2 + 3 = " + addNums(2, 3));
        Console.WriteLine("Subtraction: 17 - 20 = " + subNums(17, 20));
        Console.WriteLine("Multiplication: 5 * 3 = " + mulNums(5, 3));
        Console.WriteLine("Division: 2.4 / 2 = " + divNums(2.4, 2));




        Console.WriteLine("-----------------------banking time---------------------------");


        var sim = new BankingSimulator(100);
        var sub1 = new BankingSubscriber("bankingNotifier", sim);

        // Call the method that raises the event.
        sim.deposit(50);

        sim.withdraw(25);

        sim.withdraw(130);


    }
}