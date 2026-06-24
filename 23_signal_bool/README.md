# 23 - SC_SIGNAL `<bool>`

`sc_signal_in_if<bool>` and `sc_signal_in_if<sc_dt::sc_logic>` are interfaces that provide additional member functions appropriate for two-valued signals. sc_signal implements these functions:
  1. posedge_event() returns reference to an event that is notified whenever the value of the channel changes and the new value of the channel is true or '1'.
  2. negedge_event() returns a reference to an event that is notified whenever the value of the channel changes and the new value of the channel is false or '0'.
  3. posedge() returns true if and only if the value of the channel changed in the update phase of the immediately preceding delta cycle and at the current simulation time, and the new value of the channel is true or '1'.
  4. negedge() returns true if and only if the value of the channel changed in the update phase of the immediately preceding delta cycle and at the current simulation time, and the new value of the channel is false or '0'.