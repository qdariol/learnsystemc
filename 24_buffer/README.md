# 24 - SC_BUFFER

sc_buffer is a predefined primitive channel derived from class sc_signal.
It differs from class sc_signal in that a value-changed event is notified whenever the buffer is written rather than only when the value of the signal is changed.
E.g.,
if current value of a "signal" == 1: write 1 to it won't trigger value update event.
if current value of a "buffer" == 1: write 1 to it will trigger value update event.