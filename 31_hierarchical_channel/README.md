# 31 - Hierarchical channel

A hierarchical channel:
  1. shall inherit the sc_channel base class, which is, identical to sc_module. Thus, a hierarchical channel is a systemC module.
  2. shall inherit from an interface, to let it connect to a port.
Like a regular systemC module, a hierarchical channel may have simulation processes, ports etc.

This example shows a customized hierarchical channel that implements the sc_signal_inout_if<int>. As defined by sc_signal_inout_if, we have to implement the following functions:
  1. void write(const int&)
  2. const int& read() const
  3. const sc_event& value_changed_event() const
  4. const sc_event& default_event() const
  5. const int& get_data_ref() const
  6. bool event() const