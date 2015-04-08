# indi-hisis
INDI drivers for HiSIS CCDs

These drivers should work both with the parallel port version and with the
ISA-bus version. We have just a parallel port HiSIS 33 so testing coverage is
limited.

Compile with: `g++ $(pkg-config --libs --cflags libindi) -lindidriver hisis.cpp -o indi_hisis`


## TODO:
### (long term)
- test with PPDEV instead of direct io port access
- TDI support
- other HiSIS features? (check manual)

### (medium term)
- check features inherited from INDI::CCD
  - configuration save/restore
  - device snooping
- FITS headers
- are we abusing of DEVICE_PORT?

### (short term)
- copy connection parameters states from http://www.indilib.org/api//Lx_8cpp_source.html
  - (if I click on PP8 show all parallel ports, if I select PC16 just show 0x3BC (or nothing?))
- disconnect the device everytime the users changes connection parameters?
  - (or try to reconnect with a callback?)
  - http://www.indilib.org/api/classINDI_1_1CCD.html#adf3c8cdd71e505d4a0169f4c79ed1d0f

    updateProperties is called whenever there is a change in the CONNECTION status of the driver. This will enable the driver to react to changes of switching ON/OFF a device. For example, a driver may only define a set of properties after a device is connected, but not before. 

- remember http://www.tldp.org/HOWTO/text/IO-Port-Programming

  ioperm() can only give access to ports 0x000 through 0x3ff; for higher ports, you need to use iopl() (which gives you access to all ports at once). Use the level argument 3 (i.e., iopl(3)) to give your program access to all I/O ports (so be careful --- accessing the wrong ports can do all sorts of nasty things to your computer). Again, you need root privileges to call iopl(). See the iopl(2) manual page for details.

- why does `indi_getprop` show all `DEVICE_*` parameters two times?
