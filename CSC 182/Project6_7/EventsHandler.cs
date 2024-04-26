using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project6_7
{
    // Define a class to hold custom event info
    public class TransactionMade : EventArgs
    {
        public TransactionMade(string message)
        {
            Message = message;
        }

        public string Message { get; set; }
    }

    public class CalculatedEvent : EventArgs
    {
        public CalculatedEvent(string message)
        {
            Message = message;
        }

        public string Message { get; set; }
    }


    //Class that subscribes to an event
    class BankingSubscriber
    {
        private readonly string _id;

        public BankingSubscriber(string id, BankingSimulator sim)
        {
            _id = id;

            // Subscribe to the event
            sim.RaiseCustomEvent += HandleCustomEvent;
        }

        // Define what actions to take when the event is raised.
        void HandleCustomEvent(object? sender, TransactionMade e)
        {
            Console.WriteLine($"{_id} received this message: {e.Message}");
        }
    }

    class CalculatorSubscriber
    {
        private readonly string _id;

        public CalculatorSubscriber(string id, Calculator calc)
        {
            _id = id;

            // Subscribe to the event
            calc.RaiseCustomEvent += HandleCustomEvent;
        }

        // Define what actions to take when the event is raised.
        void HandleCustomEvent(object? sender, CalculatedEvent e)
        {
            Console.WriteLine($"{_id} received this message: {e.Message}");
        }
    }
}
