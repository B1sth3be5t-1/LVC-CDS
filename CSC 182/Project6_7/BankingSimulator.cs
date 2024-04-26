using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project6_7
{
    internal class BankingSimulator
    {
        public double balance { get; set; }


        public event EventHandler<TransactionMade>? RaiseCustomEvent;

        // Wrap event invocations inside a protected virtual method
        // to allow derived classes to override the event invocation behavior
        protected virtual void OnRaiseCustomEvent(TransactionMade e)
        {
            // Make a temporary copy of the event to avoid possibility of
            // a race condition if the last subscriber unsubscribes
            // immediately after the null check and before the event is raised.
            EventHandler<TransactionMade>? raiseEvent = RaiseCustomEvent;

            // Event will be null if there are no subscribers
            if (raiseEvent != null)
            {
                // Format the string to send inside the TransactionMade parameter
                e.Message += $" at {DateTime.Now}";

                // Call to raise the event.
                raiseEvent(this, e);
            }
        }

        public BankingSimulator(double b)
        {
            balance = b;
        }

        public void deposit(double amt)
        {
            balance += amt;

            //raise event
            OnRaiseCustomEvent(new TransactionMade("Your balance has been added to. Your balance is now: $" + balance));
        }

        public double withdraw(double amt)
        {
            double curBal = 0;

            if (amt > balance)
            {
                curBal = balance;
                balance = 0;
            }
            else {
                curBal = balance;
                balance -= amt;
            }

            OnRaiseCustomEvent(new TransactionMade("Your account has been withdrawn from. Your balance is now: $" + balance));
            return curBal;
        }
    }
}
