PAGE 118,121
TITLE TEST1 ---- 06/10/85 POWER ON SELF TEST (POST)
.286C

;-------------------------------------------------------------------------------
; BIOS I/O INTERFACE							       ;
;									       ;
;	   THESE LISTINGS PROVIDE INTERFACE INFORMATION FOR ACCESSING          ;
;	   THE BIOS ROUTINES. THE POWER ON SELF TEST IS INCLUDED.	       ;
;									       ;
;	   THE BIOS ROUTINES ARE MEANT TO BE ACCESSED THROUGH		       ;
;	   SOFTWARE INTERRUPTS ONLY. ANY ADDRESSES PRESENT IN		       ;
;	   THESE LISTINGS ARE INCLUDED ONLY FOR	COMPLETENESS,		       ;
;	   NOT FOR REFERENCE. APPLICATIONS WHICH REFERENCE ANY		       ;
;	   ABSOLUTE ADDRESSES WITHIN THE CODE SEGMENTS OF BIOS		       ;
;	   VIOLATE THE STRUCTURE AND DESIGN OF BIOS.			       ;
;									       ;
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
;   MODULE REFERENCE                                                           ;
;                                                                              ;
;    TEST1.ASM      -->  POST AND MANUFACTURING TEST ROUTINES                  ;
;      DSEG.INC	    -->   DATA SEGMENTS LOCATIONS                              ;
;      POSTEQU.INC  -->   COMMON EQUATES FOR POST AND BIOS                     ;
;      SYSDATA.INC  -->   POWER ON SELF TEST EQUATES FOR PROTECTED MODE        ;
;                          POST TEST.01 THROUGH TEST.16                        ;
;    TEST2.ASM	    -->  POST TEST AND INITIALIZATION ROUTINES                 ;
;			  POST TEST.17 THROUGH TEST.22                         ;
;    TEST3.ASM	    -->  POST EXCEPTION INTERRUPT TESTS                        ;
;    TEST4.ASM	    -->	 POST AND BIOS UTILITY ROUTINES                        ;
;			   CMOS_READ	 - READ CMOS LOCATION ROUTINE          ;
;                          CMOS WRITE	 - WRITE CMOS LOCATION ROUTINE         ;
;                          DDS	         - LOAD (DS:) WITH DATA SEGMENT        ;
;                          E_MSG	 - POST ERROR MESSAGE HANDLER          ;
;                          MFG_HALT	 - MANUFACTURING ERROR TRAP            ;
;                          P_MSG	 - POST STRING DISPLAY ROUTINE         ;
;                          ERR_BEEP	 - POST ERROR BEEP PROCEDURE           ;
;                          BEEP	         - SPEAKER BEEP CONTROL ROUTINE        ;
;                          WAITF	 - FIXED TIME WAIT ROUTINE             ;
;                          CONFIG_BAD	 - SET BAD CONFIG IN CMOS_DIAG         ;
;                          XPC_BYTE	 - DISPLAY-HEX BYTE AS 00 - FF         ; 
;                          PRT_HEX	 - DISPLAY CHARACTER                   ;
;                          PRT_SEG	 - DISPLAY SEGMENT FORMAT ADDRESS      ;
;                          PROT_PRT_HEX  - POST PROTECTED MODE DISPLAY         ;
;                          ROM_CHEECKSUM - CHECK ROM MODULES FOR CHECKSUM      ;
;                          ROM_CHECK	 - ROM SCAN AND INITIALIZE             ;
;                          KBD_RESET	 - POST KEYBOARD RESET ROUTINE         ;
;                          BLINK_INT	 - MANUFACTURING TOGGLE BIT ROUTINE    ;
;                          SET_TOD 	 - SET TIMER FROM CMOS RTC             ;
;                          D11	         - DUMMY INTERRUPT HANDLER   ->INT ??H ;
;                          RE_DIRECT 	 - HARDWARE INT  9 REDIRECT (L 2)      ;
;                          INT_287	 - HARDWARE INT 13 REDIRECT (287)      ;
;			   PROC_SHUTDOWN - 80286 RESET ROUTINE                 ;
;    TEST5.ASM	    -->  EXCEPTTON INTERRUPT TEST HANDLERS FOR POST TESTS      ;
;		           SYSINIT1	 - BUILD PROTECTED MODE POINTERS       ;
;		           GDT_BLD	 - BUILD THE GDT FOR POST              ;
;		           SIDT_BLD	 - BUILD THE IDT FOR POST              ;
;    TEST6.ASM	    -->  POST TESTS AND SYSTEM BOOT STRAP                      ;
;		           STGTST_CNT	 - SEGMENT STORAGE TEST                ;
;		           ROM_ERR	 - ROM ERROR DISPLAY ROUTINE           ;
;		           XMIT_8042	 - KEYBOARD DIAGNOSTIC OUTPUT          ;
;		           BOOT_STRAP	 - BOOT STRAP LOADER	      -INT 19H ;
;    DSKETTE.ASM    -->	 DISKETTE BIOS                                         ;
;                          DISKETTE_IO_1 - INT 13H BIOS ENTRY (40H)   -INT 13H ;
;                          DISK_INT_1	 - HARDWARE INTERRUPT HANDLER -INT 0EH ;
;                          DSKETTE_SETUP - POST SETUP DRIVE TYPES              ;
;    DISK.ASM       -->  FIXED DISK BIOS                                       ;
;                          DISK_SETUP	 - SETUP DISK VECTORS AND TEST         ;
;                          DISK_IO	 - INT 13H BIOS ENTRY         -INT 13H ;
;                          HD_IRT	 - HARDWARE INTERRUPT HANDLER -INT 16H ;
;    KYBD.ASM       -->  KEYBOARD BIOS                                         ;
;	                   KEYBOARD_IO_1 - INT 16H BIOS ENTRY	      -INT 16H ;
;	                   KB_INT_1	 - HARDWARE INTERRUPT	      -INT 09H ;
;	                   SND_DATA	 - KEYBOARD TRANSMISSION               ;
;    PRT.ASM	    -->  PRINTER ADAPTER BIOS               	      -INT 17H ;
;    RS232.ASM	    -->  COMMUNICATIONS BIOS FOR RS232	              -INT 14H ;
;    VIDEO.ASM	    -->  VIDEO BIOS		                      -INT 10H ;
;    BIOS.ASM	    -->  BIOS ROUTINES                                         ;
;		           MEMORY_SIZE_DET_1 - REAL MODE SIZE         -INT 12H ;
;		           EQUIPMENT_1   - EQUIPMENT DETERMINATION    -INT 11H ;
;		           NMI_INT_1	 - NMI HANDLER	              -INT 02H ;
;    BIOS1.ASM      -->  INTERRUPT 15H BIOS ROUTINES	              -INT 15H ;
;                          DEV_OPEN	 - NULL DEVICE OPEN HANDLER            ;
;                          DEV_CLOSE	 - NULL DEVICE CLOSE HANDLER           ;
;                          PROG_TERM	 - NULL PROGRAM TERMINATION            ;
;                          EVENT_WAIT	 - RTC EVENT WAIT/TIMEOUT ROUTINE      ;
;                          JOY_STICK	 - JOYSTICK PORT HANDLER               ;
;                          SYS_REQ	 - NULL SYSTEM REQUEST KEY             ;
;                          WAIT		 - RTC TIMED WAIT ROUTINE              ;
;                          BLOCKMOVE	 - EXTENDED MEMORY MOVE INTERFACE      ;
;                          GATE_A20	 - ADDRESS BIT 20 CONTROL              ;
;                          EXT_MEMORY	 - EXTENDED MEMORY SIZE DETERMINE      ;
;                          SET_VMODE	 - SWITCH PROCESSOR TO VIRTUAL MODE    ;
;		           DEVICE_BUSY	 - NULL DEVICE BUSY HANDLER            ;
;		           INT_COMPLETE  - NULL INTERRUPT COMPLETE HANDLER     ;
;    BIOS2.ASM	    -->  BIOS INTERRUPT ROUTINES                               ;
;		           TIME_OF_DAY_1 - TIME OF DAY ROUTINES	      -INT 1AH ;
;		           RTC_INT	 - IRQ LEVEL 8 ALARM HANDLER  -INT 70H ;
;		           PRINT_SCREEN1 - PRINT SCREEN ROUTINE	      -INT 05H ;
;		           TIMER_INT_1	 - TIMER1 INTERRUPT HANDLER  ->INT 1CH ;
;    ORGS.ASM	    -->	 COMPATIBILITY MODULE                                  ;
;		           POST ERROR MESSAGES                                 ;
;		           DISKETTE - DISK - VIDEO DATA TABLES                 ;
;-------------------------------------------------------------------------------
.LIST
