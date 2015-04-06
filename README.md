# indi-hisis
INDI drivers for HiSIS CCDs

These drivers should work both with the parallel port version and with the
ISA-bus version. We have just a parallel port HiSIS 33 so testing coverage is
limited.

Compile with: `g++ $(pkg-config --libs --cflags libindi) -lindidriver hisis.cpp -o indi_hisis`


## TODO:
- test with PPDEV instead of direct io port access
- TDI support
