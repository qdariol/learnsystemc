# 16 - Mutex

A mutex:
  1. is a predefined channel intended to model the behavior of a mutual exclusion lock used to control access to a resource shared by concurrent processes.
  2.shall be in one of two exclusive states: unlocked or locked:
    a) only one process can lock a given mutex at one time.
    b) a mutex can only be unlocked by the process hat locked it. After being unlocked, a mutex may be locked by a different process.

Member functions:
  1. int lock():
    a) If the mutex is unlocked, lock() shall lock the mutex and return.
    b) If the mutex is locked, lock() shall suspend until the mutex is unlocked (by another process).
    c) If multiple processes attempt to lock the mutex in the same delta cycle, the choice of which process instance is given the lock shall be non-deterministic.
    d) shall unconditionally return the value 0.
  2. int trylock():
    a) If the mutex is unlocked, trylock() shall lock the mutex and shall return the value 0.
    b) If the mutex is locked, trylock() shall immediately return the value –1. The mutex shall remain locked.
  3. int unlock():
    a) If the mutex is unlocked, unlock() shall return the value –1. The mutex shall remain unlocked.
    b) If the mutex was locked by a process instance other than the calling process, unlock() shall return the value –1. The mutex shall remain locked.
    c) If the mutex was locked by the calling process, member function unlock shall unlock the mutex and shall return the value 0.
      1. immediate notification shall be used to signal the act of unlocking a mutex to other processes