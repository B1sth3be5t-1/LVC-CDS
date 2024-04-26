using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project6_7
{
    public class Calculator
    {

        public event EventHandler<CalculatedEvent>? RaiseCustomEvent;

        // Wrap event invocations inside a protected virtual method
        // to allow derived classes to override the event invocation behavior
        protected virtual void OnRaiseCustomEvent(CalculatedEvent e)
        {
            // Make a temporary copy of the event to avoid possibility of
            // a race condition if the last subscriber unsubscribes
            // immediately after the null check and before the event is raised.
            EventHandler<CalculatedEvent>? raiseEvent = RaiseCustomEvent;

            // Event will be null if there are no subscribers
            if (raiseEvent != null)
            {
                // Format the string to send inside the TransactionMade parameter
                e.Message += $" at {DateTime.Now}";

                // Call to raise the event.
                raiseEvent(this, e);
            }
        }

        public double addDoubs(double a, double b)
        {
            OnRaiseCustomEvent(new CalculatedEvent("An addition calculation has been made"));
            return a + b;
        }

       
        public double subDoubs(double a, double b)
        {
            OnRaiseCustomEvent(new CalculatedEvent("A subtraction calculation has been made"));
            return a - b;
        }


        public double mulDoubs(double a, double b)
        {
            OnRaiseCustomEvent(new CalculatedEvent("A muiltiplication calculation has been made"));
            return a * b;
        }


        public double divDoubs(double a, double b)
        {
            OnRaiseCustomEvent(new CalculatedEvent("A division calculation has been made"));
            return a / b;
        }

        private void Calc_Made(object sender, System.EventArgs e)
        {
            Console.WriteLine("A calculation was made");
        }


    }
}
