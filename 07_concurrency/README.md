# 07 - Concurrency
SystemC uses simulation processes to model concurrency. It's not true concurrent execution.
When multiple processes are simulated as running concurrently, only one is executed at a particular time. However, the simulated time remain unchanged until all concurrent processes finishes their current tasks.
Thus, these processes are running concurrently on the same "simulated time". This differs from e.g. the Go language, which is real concurrency.

Let's understand the simulated concurrency with a simple example.