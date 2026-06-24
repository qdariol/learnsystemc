# 22 - Resolved signal

A resolved signal is an object of class sc_signal_resolved or class sc_signal_rv. It differs from sc_signal in that a resolved signal may be written by multiple processes, conflicting values being resolved within the channel.
  1. sc_signal_resolved is a predefined primitive channel derived from class sc_signal.
  2. sc_signal_rv is a predefined primitive channel derived from class sc_signal.
    a) sc_signal_rv is similar to sc_signal_resolved.
    b) The difference is that the argument to the base class template sc_signal is type sc_dt::sc_lv<W> instead of type sc_dt::sc_logic.

Class definition:
  1. class sc_signal_resolved: public sc_signal<sc_dt::sc_logic,SC_MANY_WRITERS>
  2. template <int W> class sc_signal_rv: public sc_signal<sc_dt::sc_lv<W>,SC_MANY_WRITERS>

Resolution table for sc_signal_resolved:
  | 0 | 1 | Z | X |
0 | 0 | X | 0 | X |
1 | X | 1 | 1 | X |
Z | 0 | 1 | Z | X |
X | X | X | X | X |

In short, a resolved signal channel can be writter by multiple processes at the same time. This differs from an sc_signal, which can only be written by one process at each delta cycle.