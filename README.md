IBM PC AT version 2 (06/10/85) BIOS commented code from IBM which shows a
correct implementation of POST and chipset initialization.

## Sources

The code is divided in the following files:

- `ios.asm`      BIOS routines INT12, INT11, INT02
- `bios1.asm`    INT15 BIOS routines
- `bios2.asm`    BIOS routines INT1A, INT70, INT5, INT8
- `disk.asm`     fixed disk BIOS INT13
- `diskette.asm` diskette BIOS INT13
- `dseg.inc`     data segment locations, KB/DSK/VIDEO data areas
- `keybd.asm`    keyboard BIOS INT16, INT9
- `modref.inc`   BIOS I/O interface
- `orgs.asm`     compatibility module
- `postequ.inc`  equates used by POST and BIOS
- `printer.asm`  printer adapter BIOS INT17
- `rs232.asm`    communications BIOS RS232 INT14
- `sysdata.inc`  protected mode EQU for post-test and BIOS routines
- `test1.asm`    POST `TEST.1` through `TEST.16`
- `test2.asm`    POST `TEST.17` through `TEST.22`
- `test3.asm`    POST exception interrupt tests
- `test4.asm`    POST and BIOS utility routines
- `test5.asm`    exception interrupt test handlers for POST
- `test6.asm`    POST and system bootstrap
- `video.asm`    video display BIOS INT10

The IBM PC AT version 2 BIOS was built using IBM MASM 2.0 on DOS.

Other legacy IBM PC BIOS sources can be found at
https://sites.google.com/site/pcdosretro/ibmpcbios

## Documentation

- `ibm-pc-techref.pdf`
complete IBM PC technical reference manual from the hardware design to the BIOS requirements
(API, memory mapping, etc.).

- `biod-pnp-specification.pdf`
modern BIOS specification with Plug-and-Play specification.

- `bios-boot-specification.pdf`
focus on boot selection specification.

- `bios-advanced-power-management.pdf`
extension for advanced power management.

- `bios-pentium-pro.pdf`
example of BIOS writer's whose purpose is to provide to
OEMs and BIOS writers recipes to initialize platforms based on a given processor
like how to enable memory controllers, PCI bridges, processor's cores, etc.
