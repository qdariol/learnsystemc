# 11 - Sensitivity

The sensitivity of a process instance is the set of events and time-outs that can potentially cause the process to be resumed or triggered.
A process instance is said to be sensitive to an event if the event has been added to the static sensitivity or dynamic sensitivity of the process instance.
A time-out occurs when a given time interval has elapsed.

Two types of sensitivities:
  1. Static sensitivity is fixed during elaboration, supported with a sensitivity list for each process in a module.
  2. Dynamic sensitivity may vary over time under the control of the process itself, support with wait() for a thread, or next_trigger() for a method.