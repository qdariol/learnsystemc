# 21 - Signal: many writers

Class definition of sc_signal:
  template <class T, sc_writer_policy WRITER_POLICY = SC_ONE_WRITER> class sc_signal: public sc_signal_inout_if<T>, public sc_prim_channel {}
1. If WRITER_POLICY == SC_ONE_WRITER, it shall be an error to write to a given signal instance from more than one process instance at any time during simulation.
2. If WRITER_POLICY == SC_MANY_WRITERS:
  a) it shall be an error to write to a given signal instance from more than one process instance during any given evaluation phase,
  b) but different process instances may write to a given signal instance during different delta cycles.

Thus, by default an sc_signal has only one writer; when declared as MANY_WRITERS, the writers can write to the signal channel at different time.

As to consumers, an sc_signal may have more than one consumers. They can all read from the signal channel at same or different time.