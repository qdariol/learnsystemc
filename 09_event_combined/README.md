# 09 - Event combined

The following forms of wait() are supported.
   1. wait(): wait on events in sensitivity list (SystemC 1.0).
   2. wait(e1): wait on event e1.
   3. wait(e1 | e2 | e3): wait on events e1, e2, or e3.
   4. wait(e1 & e2 & e3): wait on events e1, e2, and e3.
   5. wait(200, SC_NS): wait for 200 ns.
   6. wait(200, SC_NS, e1): wait on event e1, timeout after 200 ns.
   7. wait(200, SC_NS, e1 | e2 | e3): wait on events e1, e2, or e3, timeout after 200 ns.
   8. wait(200, SC_NS, e1 & e2 & e3): wait on events e1, e2, and e3, timeout after 200 ns.
   9. wait(sc_time(200, SC_NS)): wait for 200 ns.
  10. wait(sc_time(200, SC_NS), e1): wait on event e1, timeout after 200 ns.
  11. wait(sc_time(200, SC_NS), e1 | e2 | e3): wait on events e1, e2, or e3, timeout after 200 ns.
  12. wait(sc_time(200, SC_NS), e1 & e2 & e3 ): wait on events e1, e2, and e3, timeout after 200 ns.
  13. wait(200): wait for 200 clock cycles, SC_CTHREAD only (SystemC 1.0)
  14. wait(0, SC_NS): wait one delta cycle.
  15. wait(SC_ZERO_TIME): wait one delta cycle.

Note:
  a mixture of "|" operators and "&" operators is not supported in SystemC 2.0