# 29 - Communication: port array

When declarying a port:
  1. the first argument is the name of an interface proper, which is also the type of the port:
    a port can only be bound to a channel derived from the type of the port or to another port or export with a type derived from the type of the port.
  2. the second argument is an optional integer value that specifies the maximum number of channel instances to which the port instance may be bound:
    a) the default value is 1.
    b) if the value is zero, the port may be bound to an arbitrary number of channel instances.
    c) it's an error to bind a port to more channel instances than the number permitted.
  3. the third argument is an optional port policy of type sc_port_policy that determines the rules for binding multiports and the rules for unbound ports:
    a) [default] SC_ONE_OR_MORE_BOUND: the port shall be bound to one or more channels, the maximum number being determined by the value of the second argument. It's an error for the port to remain unbound at the end of elaboration.
    b) SC_ZERO_OR_MORE_BOUND: the port shall be bound to zero or more channels, the maximum number being determined by the value of the second argument. The port may remain unbound at the end of elaboration.
    c) SC_ALL_BOUND: the port shall be bound to exactly the number of channel instances given by value of the second argument, no more and no less, provided that value is greater than zero.
      1) If the value of the second argument is zero, policy SC_ALL_BOUND has the same meaning as policy SC_ONE_OR_MORE_BOUND.
      2) It's an error for the port to remain unbound at the end of elaboration, or to be bound to fewer channel than the number required by the second argument.

It's an error to bind a given port to a given channel more than once, whether directly or through another port.

Another way to define port array is using the C/C++ array syntax: sc_port<IF> p[10] or vector<sc_port<IF>> p(10);

Example:
  1. sc_port<IF>                         // Bound to exactly 1 channel instance
  2. sc_port<IF,0>                       // Bound to 1 or more channel instances, with no upper limit
  3. sc_port<IF,3>                       // Bound to 1, 2, or 3 channel instances
  4. sc_port<IF,0,SC_ZERO_OR_MORE_BOUND> // Bound to 0 or more channel instances, with no upper limit
  5. sc_port<IF,1,SC_ZERO_OR_MORE_BOUND> // Bound to 0 or 1 channel instances
  6. sc_port<IF,3,SC_ZERO_OR_MORE_BOUND> // Bound to 0, 1, 2, or 3 channel instances
  7. sc_port<IF,3,SC_ALL_BOUND>          // Bound to exactly 3 channel instances
  8. sc_port<IF, 3>                      // an array of 3 ports, each binds to exactly 1 channel instance
  9. vector<sc_port<IF>> p(3)            // an array of 3 ports, each binds to exactly 1 channel instance