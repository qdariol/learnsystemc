# 17 - Semaphore

A semaphore:
  1. is a predefined channel intended to model the behavior of a software semaphore used to provide limited concurrent access to a shared resource.
  2. has an integer value, the semaphore value, which is set to the permitted number of concurrent accesses when the semaphore is constructed.
    a) if the initial value is one, the semaphore is equivelent to a mutex.

Member functions:
  1. int wait():
    a) If the semaphore value is greater than 0, wait() shall decrement the semaphore value and return.
    b) If the semaphore value is equal to 0, wait() shall suspend until the semaphore value is incremented (by another process).
    c) Shall unconditionally return the value 0.
  2. int trywait():
    a) If the semaphore value is greater than 0, trywait() shall decrement the semaphore value and shall return the value 0.
    b) If the semaphore value is equal to 0, trywait() shall immediately return the value –1 without modifying the semaphore value.
  3. int post():
    a) shall increment the semaphore value.
    b) shall use immediate notification to signal the act of incrementing the semaphore value to any waiting processes.
    c) shall unconditionally return the value 0.
  4. int get_value(): shall return the semaphore value.