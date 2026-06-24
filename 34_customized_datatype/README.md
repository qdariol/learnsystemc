# 34 - Customized Data Type

sc_signal<T> and sc_fifo<T> can be used with various data types. SystemC has already supported T for build-in data types.
In order to use customized data types for sc_signal and sc_fifo, the following member functions shall be implemented for the data type:
  1. assignment operator, i.e. operator=(): needed for read and write methods
  2. equality operator, i.e. operator==(): needed by sc_signal for value_changed_event()
  3. streaming output, i.e. ostream& operator<<(): needed to print the data structure
  4. sc_trace(): allow the data type to be used with the systemC trace facility; enables viewing traced data with a wavefor viewer.