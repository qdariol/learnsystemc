# 18 - FIFO
sc_fifo:
  1. is a predefined primitive channel intended to model the behavior of a fifo, i.e., a first in first out buffer.
  2. has a number of slots for storing values. The number of slots is fixed when the object is constructed.
  3. implements the sc_fifo_in_if<T> interface and the sc_fifo_out_if<T> interface.

Constructors:
  1. explicit sc_fifo(int size_ = 16): calls the base class constructor from its initializer list as: sc_prim_channel(sc_gen_unique_name( "fifo" ))
  2. explicit sc_fifo(const char* name_, int size_ = 16): calls the base class constructor from its initializer list as: sc_prim_channel(name_)
  Both constructors initialize the number of slots in the fifo to the value given by the parameter size_. The number of slots shall be greater than zero.

Member functions for read:
  1. void read(T&), T read():
    a) return the value least recently written into the fifo and remove that value from the fifo such that it cannot be read again.
    b) the order in which values are read from the fifo shall precisely match the order in which values were written into the fifo.
    c) values written into the fifo during the current delta cycle are not available for reading in that delta cycle, but become available for reading in the immediately following delta cycle.
    d) if the fifo is empty, shall suspend until the data-written event is notified.
  2. bool nb_read(T&):
    a), b), c) same as read()
    d) if the fifo is empty, member function nb_read shall return immediately without modifying the state of the fifo, without calling request_update, and with a return value of false. Otherwise, if a value is available for reading, the return value of nb_read() shall be true.
  3. operator T(): equivalent to "operator T() {return read();}""

Member functions for write:
  1. write(const T&):
    a) write the value passed as an argument into the fifo.
    b) multiple values may be written within a single delta cycle.
    c) if values are read from the fifo during the current delta cycle, the empty slots in the fifo so created do not become free for the purposes of writing until the immediately following delta cycle.
    d) if the fifo is full, write() shall suspend until the data-read event is notified.
  2. bool nb_write(const T&):
    a), b), c) same as write()
    d) if the fifo is full, nb_write() shall return immediately without modifying the state of the fifo, without calling request_update, and with a return value of false. Otherwise, the return value of nb_write() shall be true.
  3. operator=: equivalent to "sc_fifo<T>& operator= (const T& a) {write(a); return *this;}"

Member functions for events:
  1. sc_event& data_written_event(): shall return a reference to the data-written event, that is notified in the delta notification phase that occurs at the end of the delta cycle in which a value is written into the fifo.
  2. sc_event& data_read_event(): shall return a reference to the data-read event, that is notified in the delta notification phase that occurs at the end of the delta cycle in which a value is read from the fifo.

Member functions for available values and free slots:
  1. int num_available(): returns the number of values that are available for reading in the current delta cycle. The calculation shall deduct any values read during the current delta cycle but shall not add any values written during the current delta cycle.
  2. int num_free(): returns the number of empty slots that are free for writing in the current delta cycle. The calculation shall deduct any slots written during the current delta cycle but shall not add any slots made free by reading in the current delta cycle.