using static System.Math;
using System.IO;

namespace TeleprompterConsole;

internal class TelePrompterConfig
{
    public int DelayInMilliseconds { get; private set; } = 200;
    public void UpdateDelay(int increment) // negative to speed up
    {
        var newDelay = Min(DelayInMilliseconds + increment, 1000);
        newDelay = Max(newDelay, 20);
        DelayInMilliseconds = newDelay;
    }
    public bool Done { get; private set; }
    public void SetDone()
    {
        Done = true;
    }
}



internal class Program
{
    static async Task Main(string[] args)
    {
        //await RunTeleprompter();

        List<int> ints = new List<int>();

        double avg = 0;
        int max = -100000, min = 100000, tot = 0, num = 0;



        StreamReader sr = new StreamReader("input.txt");
        string cur;

        while ((cur = sr.ReadLine()) != null)
        {
                num = int.Parse(cur);
                ints.Add(num);

                tot += num;
                if (num > max) max = num;
                if (num < min) min = num;
                num++;

            }
        avg = tot * 1.0 / num;

        double d = Math.Max(max - avg, avg - min);

        List<int> remaining = new List<int>();


        foreach (int i in ints)
        {
            if (Abs(avg - i) <= .75 * d) remaining.Add(i);
        }


        string numStr = "Total number of remaining ints: " + remaining.Count + Environment.NewLine;

        string docPath = Path.Combine(Directory.GetCurrentDirectory(), "output.txt");

        File.WriteAllText(docPath, numStr);

        List<string> lines = new List<string>();

        foreach (int r in remaining) {
            lines.Add(r.ToString());        
        }

        File.AppendAllLines(docPath, lines);
    }







    private static async Task RunTeleprompter()
    {
        var config = new TelePrompterConfig();
        var displayTask = ShowTeleprompter(config);

        var speedTask = GetInput(config);
        await Task.WhenAny(displayTask, speedTask);
    }


    private static async Task ShowTeleprompter(TelePrompterConfig config)
    {
        var words = ReadFrom("input.txt");
        foreach (var word in words)
        {
            Console.Write(word);
            if (!string.IsNullOrWhiteSpace(word))
            {
                await Task.Delay(config.DelayInMilliseconds);
            }
        }
        config.SetDone();
    }

    private static async Task GetInput(TelePrompterConfig config)
    {
        Action work = () =>
        {
            do
            {
                var key = Console.ReadKey(true);
                if (key.KeyChar == '>')
                    config.UpdateDelay(-10);
                else if (key.KeyChar == '<')
                    config.UpdateDelay(10);
                else if (key.KeyChar == 'X' || key.KeyChar == 'x')
                    config.SetDone();
            } while (!config.Done);
        };
        await Task.Run(work);
    }

    static IEnumerable<string> ReadFrom(string file)
    {
        string? line;
        using (var reader = File.OpenText(file))
        {
            while ((line = reader.ReadLine()) != null)
            {
                var words = line.Split(' ');
                var lineLength = 0;
                foreach (var word in words)
                {
                    yield return word + " ";
                    lineLength += word.Length + 1;
                    if (lineLength > 70)
                    {
                        yield return Environment.NewLine;
                        lineLength = 0;
                    }
                }
                yield return Environment.NewLine;
            }
        }
    }

}