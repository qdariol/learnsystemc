# 10 - Delta Cycle

A delta cycle can be thought of as a very small step of time within the simulation, which does not increase the user-visible time.
A delta cycle is comprised of separate evaluate and update phases, and multiple delta cycles may occur at a particular simulated time.
When a signal assignment occurs, other processes do not see the newly assigned value until the next delta cycle.

When is delta cycle used:
  1. notify(SC_ZERO_TIME) causes the event to be notified in the evaluate phase of the next delta cycle, this is called a "delta notification".
  2. A (direct or indirect) call to request_update() causes the update() method to be called in the update phase of the current delta cycle.