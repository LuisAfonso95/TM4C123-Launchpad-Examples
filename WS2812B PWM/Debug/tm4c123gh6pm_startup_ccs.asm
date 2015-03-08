;******************************************************************************
;* TI ARM C/C++ Codegen                                             PC v5.1.6 *
;* Date/Time created: Sun Nov 09 01:02:07 2014                                *
;******************************************************************************
	.compiler_opts --abi=eabi --arm_vmrs_si_workaround=on --code_state=16 --diag_wrap=off --disable_dual_state --embedded_constants=on --endian=little --float_support=FPv4SPD16 --hll_source=on --object_format=elf --silicon_version=7M4 --symdebug:dwarf --symdebug:dwarf_version=3 --unaligned_access=on 
	.thumb

$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$CU, DW_AT_producer("TI TI ARM C/C++ Codegen PC v5.1.6 Copyright (c) 1996-2014 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("D:\MEOCloud\MEOCloud\WorkSpace CCS\CCS TM4C123\WS2812B PWM\Debug")
$C$DW$1	.dwtag  DW_TAG_variable, DW_AT_name("__STACK_TOP")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("__STACK_TOP")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$1, DW_AT_decl_line(0x32)
	.dwattr $C$DW$1, DW_AT_decl_column(0x11)
	.global	g_pfnVectors
	.sect	".intvecs"
	.align	4
	.elfsym	g_pfnVectors,SYM_SIZE(620)
g_pfnVectors:
	.bits	__STACK_TOP,32		; g_pfnVectors[0] @ 0
	.bits	ResetISR,32		; g_pfnVectors[1] @ 32
	.bits	NmiSR,32		; g_pfnVectors[2] @ 64
	.bits	FaultISR,32		; g_pfnVectors[3] @ 96
	.bits	IntDefaultHandler,32		; g_pfnVectors[4] @ 128
	.bits	IntDefaultHandler,32		; g_pfnVectors[5] @ 160
	.bits	IntDefaultHandler,32		; g_pfnVectors[6] @ 192
	.bits	0,32			; g_pfnVectors[7] @ 224
	.bits	0,32			; g_pfnVectors[8] @ 256
	.bits	0,32			; g_pfnVectors[9] @ 288
	.bits	0,32			; g_pfnVectors[10] @ 320
	.bits	IntDefaultHandler,32		; g_pfnVectors[11] @ 352
	.bits	IntDefaultHandler,32		; g_pfnVectors[12] @ 384
	.bits	0,32			; g_pfnVectors[13] @ 416
	.bits	IntDefaultHandler,32		; g_pfnVectors[14] @ 448
	.bits	IntDefaultHandler,32		; g_pfnVectors[15] @ 480
	.bits	IntDefaultHandler,32		; g_pfnVectors[16] @ 512
	.bits	IntDefaultHandler,32		; g_pfnVectors[17] @ 544
	.bits	IntDefaultHandler,32		; g_pfnVectors[18] @ 576
	.bits	IntDefaultHandler,32		; g_pfnVectors[19] @ 608
	.bits	IntDefaultHandler,32		; g_pfnVectors[20] @ 640
	.bits	IntDefaultHandler,32		; g_pfnVectors[21] @ 672
	.bits	IntDefaultHandler,32		; g_pfnVectors[22] @ 704
	.bits	IntDefaultHandler,32		; g_pfnVectors[23] @ 736
	.bits	IntDefaultHandler,32		; g_pfnVectors[24] @ 768
	.bits	IntDefaultHandler,32		; g_pfnVectors[25] @ 800
	.bits	IntDefaultHandler,32		; g_pfnVectors[26] @ 832
	.bits	IntDefaultHandler,32		; g_pfnVectors[27] @ 864
	.bits	IntDefaultHandler,32		; g_pfnVectors[28] @ 896
	.bits	IntDefaultHandler,32		; g_pfnVectors[29] @ 928
	.bits	IntDefaultHandler,32		; g_pfnVectors[30] @ 960
	.bits	IntDefaultHandler,32		; g_pfnVectors[31] @ 992
	.bits	IntDefaultHandler,32		; g_pfnVectors[32] @ 1024
	.bits	IntDefaultHandler,32		; g_pfnVectors[33] @ 1056
	.bits	IntDefaultHandler,32		; g_pfnVectors[34] @ 1088
	.bits	IntDefaultHandler,32		; g_pfnVectors[35] @ 1120
	.bits	IntDefaultHandler,32		; g_pfnVectors[36] @ 1152
	.bits	IntDefaultHandler,32		; g_pfnVectors[37] @ 1184
	.bits	IntDefaultHandler,32		; g_pfnVectors[38] @ 1216
	.bits	IntDefaultHandler,32		; g_pfnVectors[39] @ 1248
	.bits	IntDefaultHandler,32		; g_pfnVectors[40] @ 1280
	.bits	IntDefaultHandler,32		; g_pfnVectors[41] @ 1312
	.bits	IntDefaultHandler,32		; g_pfnVectors[42] @ 1344
	.bits	IntDefaultHandler,32		; g_pfnVectors[43] @ 1376
	.bits	IntDefaultHandler,32		; g_pfnVectors[44] @ 1408
	.bits	IntDefaultHandler,32		; g_pfnVectors[45] @ 1440
	.bits	IntDefaultHandler,32		; g_pfnVectors[46] @ 1472
	.bits	IntDefaultHandler,32		; g_pfnVectors[47] @ 1504
	.bits	IntDefaultHandler,32		; g_pfnVectors[48] @ 1536
	.bits	IntDefaultHandler,32		; g_pfnVectors[49] @ 1568
	.bits	IntDefaultHandler,32		; g_pfnVectors[50] @ 1600
	.bits	IntDefaultHandler,32		; g_pfnVectors[51] @ 1632
	.bits	IntDefaultHandler,32		; g_pfnVectors[52] @ 1664
	.bits	IntDefaultHandler,32		; g_pfnVectors[53] @ 1696
	.bits	IntDefaultHandler,32		; g_pfnVectors[54] @ 1728
	.bits	IntDefaultHandler,32		; g_pfnVectors[55] @ 1760
	.bits	IntDefaultHandler,32		; g_pfnVectors[56] @ 1792
	.bits	0,32			; g_pfnVectors[57] @ 1824
	.bits	0,32			; g_pfnVectors[58] @ 1856
	.bits	IntDefaultHandler,32		; g_pfnVectors[59] @ 1888
	.bits	IntDefaultHandler,32		; g_pfnVectors[60] @ 1920
	.bits	IntDefaultHandler,32		; g_pfnVectors[61] @ 1952
	.bits	IntDefaultHandler,32		; g_pfnVectors[62] @ 1984
	.bits	IntDefaultHandler,32		; g_pfnVectors[63] @ 2016
	.bits	IntDefaultHandler,32		; g_pfnVectors[64] @ 2048
	.bits	IntDefaultHandler,32		; g_pfnVectors[65] @ 2080
	.bits	IntDefaultHandler,32		; g_pfnVectors[66] @ 2112
	.bits	IntDefaultHandler,32		; g_pfnVectors[67] @ 2144
	.bits	0,32			; g_pfnVectors[68] @ 2176
	.bits	0,32			; g_pfnVectors[69] @ 2208
	.bits	IntDefaultHandler,32		; g_pfnVectors[70] @ 2240
	.bits	IntDefaultHandler,32		; g_pfnVectors[71] @ 2272
	.bits	IntDefaultHandler,32		; g_pfnVectors[72] @ 2304
	.bits	IntDefaultHandler,32		; g_pfnVectors[73] @ 2336
	.bits	IntDefaultHandler,32		; g_pfnVectors[74] @ 2368
	.bits	IntDefaultHandler,32		; g_pfnVectors[75] @ 2400
	.bits	IntDefaultHandler,32		; g_pfnVectors[76] @ 2432
	.bits	IntDefaultHandler,32		; g_pfnVectors[77] @ 2464
	.bits	IntDefaultHandler,32		; g_pfnVectors[78] @ 2496
	.bits	IntDefaultHandler,32		; g_pfnVectors[79] @ 2528
	.bits	0,32			; g_pfnVectors[80] @ 2560
	.bits	0,32			; g_pfnVectors[81] @ 2592
	.bits	0,32			; g_pfnVectors[82] @ 2624
	.bits	0,32			; g_pfnVectors[83] @ 2656
	.bits	IntDefaultHandler,32		; g_pfnVectors[84] @ 2688
	.bits	IntDefaultHandler,32		; g_pfnVectors[85] @ 2720
	.bits	IntDefaultHandler,32		; g_pfnVectors[86] @ 2752
	.bits	IntDefaultHandler,32		; g_pfnVectors[87] @ 2784
	.bits	0,32			; g_pfnVectors[88] @ 2816
	.bits	0,32			; g_pfnVectors[89] @ 2848
	.bits	0,32			; g_pfnVectors[90] @ 2880
	.bits	0,32			; g_pfnVectors[91] @ 2912
	.bits	0,32			; g_pfnVectors[92] @ 2944
	.bits	0,32			; g_pfnVectors[93] @ 2976
	.bits	0,32			; g_pfnVectors[94] @ 3008
	.bits	0,32			; g_pfnVectors[95] @ 3040
	.bits	0,32			; g_pfnVectors[96] @ 3072
	.bits	0,32			; g_pfnVectors[97] @ 3104
	.bits	0,32			; g_pfnVectors[98] @ 3136
	.bits	0,32			; g_pfnVectors[99] @ 3168
	.bits	0,32			; g_pfnVectors[100] @ 3200
	.bits	0,32			; g_pfnVectors[101] @ 3232
	.bits	0,32			; g_pfnVectors[102] @ 3264
	.bits	0,32			; g_pfnVectors[103] @ 3296
	.bits	0,32			; g_pfnVectors[104] @ 3328
	.bits	0,32			; g_pfnVectors[105] @ 3360
	.bits	0,32			; g_pfnVectors[106] @ 3392
	.bits	0,32			; g_pfnVectors[107] @ 3424
	.bits	IntDefaultHandler,32		; g_pfnVectors[108] @ 3456
	.bits	IntDefaultHandler,32		; g_pfnVectors[109] @ 3488
	.bits	IntDefaultHandler,32		; g_pfnVectors[110] @ 3520
	.bits	IntDefaultHandler,32		; g_pfnVectors[111] @ 3552
	.bits	IntDefaultHandler,32		; g_pfnVectors[112] @ 3584
	.bits	IntDefaultHandler,32		; g_pfnVectors[113] @ 3616
	.bits	IntDefaultHandler,32		; g_pfnVectors[114] @ 3648
	.bits	IntDefaultHandler,32		; g_pfnVectors[115] @ 3680
	.bits	IntDefaultHandler,32		; g_pfnVectors[116] @ 3712
	.bits	IntDefaultHandler,32		; g_pfnVectors[117] @ 3744
	.bits	IntDefaultHandler,32		; g_pfnVectors[118] @ 3776
	.bits	IntDefaultHandler,32		; g_pfnVectors[119] @ 3808
	.bits	IntDefaultHandler,32		; g_pfnVectors[120] @ 3840
	.bits	IntDefaultHandler,32		; g_pfnVectors[121] @ 3872
	.bits	IntDefaultHandler,32		; g_pfnVectors[122] @ 3904
	.bits	0,32			; g_pfnVectors[123] @ 3936
	.bits	0,32			; g_pfnVectors[124] @ 3968
	.bits	IntDefaultHandler,32		; g_pfnVectors[125] @ 4000
	.bits	IntDefaultHandler,32		; g_pfnVectors[126] @ 4032
	.bits	IntDefaultHandler,32		; g_pfnVectors[127] @ 4064
	.bits	IntDefaultHandler,32		; g_pfnVectors[128] @ 4096
	.bits	IntDefaultHandler,32		; g_pfnVectors[129] @ 4128
	.bits	0,32			; g_pfnVectors[130] @ 4160
	.bits	0,32			; g_pfnVectors[131] @ 4192
	.bits	IntDefaultHandler,32		; g_pfnVectors[132] @ 4224
	.bits	IntDefaultHandler,32		; g_pfnVectors[133] @ 4256
	.bits	IntDefaultHandler,32		; g_pfnVectors[134] @ 4288
	.bits	IntDefaultHandler,32		; g_pfnVectors[135] @ 4320
	.bits	IntDefaultHandler,32		; g_pfnVectors[136] @ 4352
	.bits	IntDefaultHandler,32		; g_pfnVectors[137] @ 4384
	.bits	IntDefaultHandler,32		; g_pfnVectors[138] @ 4416
	.bits	IntDefaultHandler,32		; g_pfnVectors[139] @ 4448
	.bits	IntDefaultHandler,32		; g_pfnVectors[140] @ 4480
	.bits	IntDefaultHandler,32		; g_pfnVectors[141] @ 4512
	.bits	IntDefaultHandler,32		; g_pfnVectors[142] @ 4544
	.bits	IntDefaultHandler,32		; g_pfnVectors[143] @ 4576
	.bits	IntDefaultHandler,32		; g_pfnVectors[144] @ 4608
	.bits	IntDefaultHandler,32		; g_pfnVectors[145] @ 4640
	.bits	IntDefaultHandler,32		; g_pfnVectors[146] @ 4672
	.bits	IntDefaultHandler,32		; g_pfnVectors[147] @ 4704
	.bits	IntDefaultHandler,32		; g_pfnVectors[148] @ 4736
	.bits	IntDefaultHandler,32		; g_pfnVectors[149] @ 4768
	.bits	IntDefaultHandler,32		; g_pfnVectors[150] @ 4800
	.bits	IntDefaultHandler,32		; g_pfnVectors[151] @ 4832
	.bits	IntDefaultHandler,32		; g_pfnVectors[152] @ 4864
	.bits	IntDefaultHandler,32		; g_pfnVectors[153] @ 4896
	.bits	IntDefaultHandler,32		; g_pfnVectors[154] @ 4928

$C$DW$2	.dwtag  DW_TAG_variable, DW_AT_name("g_pfnVectors")
	.dwattr $C$DW$2, DW_AT_TI_symbol_name("g_pfnVectors")
	.dwattr $C$DW$2, DW_AT_location[DW_OP_addr g_pfnVectors]
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$2, DW_AT_external
	.dwattr $C$DW$2, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$2, DW_AT_decl_line(0x43)
	.dwattr $C$DW$2, DW_AT_decl_column(0x0f)
;	S:\ti\ccsv6\tools\compiler\arm_5.1.6\bin\armacpia.exe -@C:\\Users\\Asus\\AppData\\Local\\Temp\\0570812 
	.sect	".text"
	.clink
	.thumbfunc ResetISR
	.thumb
	.global	ResetISR

$C$DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("ResetISR")
	.dwattr $C$DW$3, DW_AT_low_pc(ResetISR)
	.dwattr $C$DW$3, DW_AT_high_pc(0x00)
	.dwattr $C$DW$3, DW_AT_TI_symbol_name("ResetISR")
	.dwattr $C$DW$3, DW_AT_external
	.dwattr $C$DW$3, DW_AT_TI_begin_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$3, DW_AT_TI_begin_line(0xee)
	.dwattr $C$DW$3, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$3, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$3, DW_AT_decl_line(0xee)
	.dwattr $C$DW$3, DW_AT_decl_column(0x01)
	.dwattr $C$DW$3, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 239,column 1,is_stmt,address ResetISR,isa 1

	.dwfde $C$DW$CIE, ResetISR

;*****************************************************************************
;* FUNCTION NAME: ResetISR                                                   *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         : LR                                                  *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
ResetISR:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 244,column 5,is_stmt,isa 1
    .global _c_int00
    b.w     _c_int00
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 246,column 1,is_stmt,isa 1
$C$DW$4	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$4, DW_AT_low_pc(0x00)
	.dwattr $C$DW$4, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$3, DW_AT_TI_end_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$3, DW_AT_TI_end_line(0xf6)
	.dwattr $C$DW$3, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$3

	.sect	".text"
	.clink
	.thumbfunc NmiSR
	.thumb

$C$DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("NmiSR")
	.dwattr $C$DW$5, DW_AT_low_pc(NmiSR)
	.dwattr $C$DW$5, DW_AT_high_pc(0x00)
	.dwattr $C$DW$5, DW_AT_TI_symbol_name("NmiSR")
	.dwattr $C$DW$5, DW_AT_TI_begin_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$5, DW_AT_TI_begin_line(0x100)
	.dwattr $C$DW$5, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$5, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$5, DW_AT_decl_line(0x100)
	.dwattr $C$DW$5, DW_AT_decl_column(0x01)
	.dwattr $C$DW$5, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 257,column 1,is_stmt,address NmiSR,isa 1

	.dwfde $C$DW$CIE, NmiSR

;*****************************************************************************
;* FUNCTION NAME: NmiSR                                                      *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         : LR                                                  *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
NmiSR:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 261,column 11,is_stmt,isa 1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L1||
;*
;*   Loop source line                : 261
;*   Loop closing brace source line  : 263
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L1||:    
        B         ||$C$L1||             ; [DPU_3_PIPE] |261| 
        ; BRANCH OCCURS {||$C$L1||}      ; [] |261| 
;* --------------------------------------------------------------------------*
	.dwattr $C$DW$5, DW_AT_TI_end_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$5, DW_AT_TI_end_line(0x108)
	.dwattr $C$DW$5, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$5

	.sect	".text"
	.clink
	.thumbfunc FaultISR
	.thumb

$C$DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("FaultISR")
	.dwattr $C$DW$6, DW_AT_low_pc(FaultISR)
	.dwattr $C$DW$6, DW_AT_high_pc(0x00)
	.dwattr $C$DW$6, DW_AT_TI_symbol_name("FaultISR")
	.dwattr $C$DW$6, DW_AT_TI_begin_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$6, DW_AT_TI_begin_line(0x112)
	.dwattr $C$DW$6, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$6, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$6, DW_AT_decl_line(0x112)
	.dwattr $C$DW$6, DW_AT_decl_column(0x01)
	.dwattr $C$DW$6, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 275,column 1,is_stmt,address FaultISR,isa 1

	.dwfde $C$DW$CIE, FaultISR

;*****************************************************************************
;* FUNCTION NAME: FaultISR                                                   *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         : LR                                                  *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
FaultISR:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 279,column 11,is_stmt,isa 1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L2||
;*
;*   Loop source line                : 279
;*   Loop closing brace source line  : 281
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L2||:    
        B         ||$C$L2||             ; [DPU_3_PIPE] |279| 
        ; BRANCH OCCURS {||$C$L2||}      ; [] |279| 
;* --------------------------------------------------------------------------*
	.dwattr $C$DW$6, DW_AT_TI_end_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$6, DW_AT_TI_end_line(0x11a)
	.dwattr $C$DW$6, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$6

	.sect	".text"
	.clink
	.thumbfunc IntDefaultHandler
	.thumb

$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("IntDefaultHandler")
	.dwattr $C$DW$7, DW_AT_low_pc(IntDefaultHandler)
	.dwattr $C$DW$7, DW_AT_high_pc(0x00)
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("IntDefaultHandler")
	.dwattr $C$DW$7, DW_AT_TI_begin_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$7, DW_AT_TI_begin_line(0x124)
	.dwattr $C$DW$7, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$7, DW_AT_decl_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$7, DW_AT_decl_line(0x124)
	.dwattr $C$DW$7, DW_AT_decl_column(0x01)
	.dwattr $C$DW$7, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 293,column 1,is_stmt,address IntDefaultHandler,isa 1

	.dwfde $C$DW$CIE, IntDefaultHandler

;*****************************************************************************
;* FUNCTION NAME: IntDefaultHandler                                          *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         : LR                                                  *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
IntDefaultHandler:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwpsn	file "../tm4c123gh6pm_startup_ccs.c",line 297,column 11,is_stmt,isa 1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L3||
;*
;*   Loop source line                : 297
;*   Loop closing brace source line  : 299
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L3||:    
        B         ||$C$L3||             ; [DPU_3_PIPE] |297| 
        ; BRANCH OCCURS {||$C$L3||}      ; [] |297| 
;* --------------------------------------------------------------------------*
	.dwattr $C$DW$7, DW_AT_TI_end_file("../tm4c123gh6pm_startup_ccs.c")
	.dwattr $C$DW$7, DW_AT_TI_end_line(0x12c)
	.dwattr $C$DW$7, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$7

;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	__STACK_TOP

;******************************************************************************
;* BUILD ATTRIBUTES                                                           *
;******************************************************************************
	.battr "aeabi", Tag_File, 1, Tag_ABI_PCS_wchar_t(2)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_rounding(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_denormal(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_exceptions(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_number_model(1)
	.battr "aeabi", Tag_File, 1, Tag_ABI_enum_size(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_optimization_goals(5)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_optimization_goals(0)
	.battr "TI", Tag_File, 1, Tag_Bitfield_layout(2)
	.battr "TI", Tag_File, 1, Tag_FP_interface(1)

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
$C$DW$T$2	.dwtag  DW_TAG_unspecified_type
	.dwattr $C$DW$T$2, DW_AT_name("void")

$C$DW$T$19	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$19, DW_AT_language(DW_LANG_C)
$C$DW$T$20	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$20, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$20, DW_AT_address_class(0x20)
$C$DW$T$21	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$21, DW_AT_type(*$C$DW$T$20)

$C$DW$T$22	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$22, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$22, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$22, DW_AT_byte_size(0x26c)
$C$DW$8	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$8, DW_AT_upper_bound(0x9a)
	.dwendtag $C$DW$T$22

$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$23	.dwtag  DW_TAG_typedef, DW_AT_name("int8_t")
	.dwattr $C$DW$T$23, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$23, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$23, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$23, DW_AT_decl_line(0x2a)
	.dwattr $C$DW$T$23, DW_AT_decl_column(0x1d)
$C$DW$T$24	.dwtag  DW_TAG_typedef, DW_AT_name("int_least8_t")
	.dwattr $C$DW$T$24, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$T$24, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$24, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$24, DW_AT_decl_line(0x37)
	.dwattr $C$DW$T$24, DW_AT_decl_column(0x17)
$C$DW$T$6	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr $C$DW$T$6, DW_AT_name("unsigned char")
	.dwattr $C$DW$T$6, DW_AT_byte_size(0x01)
$C$DW$T$25	.dwtag  DW_TAG_typedef, DW_AT_name("uint8_t")
	.dwattr $C$DW$T$25, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$25, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$25, DW_AT_decl_line(0x2b)
	.dwattr $C$DW$T$25, DW_AT_decl_column(0x1c)
$C$DW$T$26	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least8_t")
	.dwattr $C$DW$T$26, DW_AT_type(*$C$DW$T$25)
	.dwattr $C$DW$T$26, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$26, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$26, DW_AT_decl_line(0x38)
	.dwattr $C$DW$T$26, DW_AT_decl_column(0x16)
$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x02)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x02)
$C$DW$T$27	.dwtag  DW_TAG_typedef, DW_AT_name("int16_t")
	.dwattr $C$DW$T$27, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$27, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$27, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$27, DW_AT_decl_line(0x2c)
	.dwattr $C$DW$T$27, DW_AT_decl_column(0x1d)
$C$DW$T$28	.dwtag  DW_TAG_typedef, DW_AT_name("int_least16_t")
	.dwattr $C$DW$T$28, DW_AT_type(*$C$DW$T$27)
	.dwattr $C$DW$T$28, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$28, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$28, DW_AT_decl_line(0x3a)
	.dwattr $C$DW$T$28, DW_AT_decl_column(0x17)
$C$DW$T$9	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$9, DW_AT_name("unsigned short")
	.dwattr $C$DW$T$9, DW_AT_byte_size(0x02)
$C$DW$T$29	.dwtag  DW_TAG_typedef, DW_AT_name("uint16_t")
	.dwattr $C$DW$T$29, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$29, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$29, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$29, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$29, DW_AT_decl_column(0x1c)
$C$DW$T$30	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least16_t")
	.dwattr $C$DW$T$30, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$30, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$30, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$30, DW_AT_decl_line(0x3b)
	.dwattr $C$DW$T$30, DW_AT_decl_column(0x16)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x04)
$C$DW$T$31	.dwtag  DW_TAG_typedef, DW_AT_name("int32_t")
	.dwattr $C$DW$T$31, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$31, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$31, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$31, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$31, DW_AT_decl_column(0x1d)
$C$DW$T$32	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast16_t")
	.dwattr $C$DW$T$32, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$T$32, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$32, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$32, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$32, DW_AT_decl_column(0x17)
$C$DW$T$33	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast32_t")
	.dwattr $C$DW$T$33, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$T$33, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$33, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$33, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$T$33, DW_AT_decl_column(0x17)
$C$DW$T$34	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast8_t")
	.dwattr $C$DW$T$34, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$T$34, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$34, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$34, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$34, DW_AT_decl_column(0x17)
$C$DW$T$35	.dwtag  DW_TAG_typedef, DW_AT_name("int_least32_t")
	.dwattr $C$DW$T$35, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$T$35, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$35, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$35, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$35, DW_AT_decl_column(0x17)
$C$DW$T$36	.dwtag  DW_TAG_typedef, DW_AT_name("intptr_t")
	.dwattr $C$DW$T$36, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$36, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$36, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$36, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$36, DW_AT_decl_column(0x1a)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x04)
$C$DW$T$37	.dwtag  DW_TAG_typedef, DW_AT_name("uint32_t")
	.dwattr $C$DW$T$37, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$37, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$37, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$37, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$37, DW_AT_decl_column(0x1c)
$C$DW$T$39	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast16_t")
	.dwattr $C$DW$T$39, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$T$39, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$39, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$39, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$39, DW_AT_decl_column(0x16)
$C$DW$T$40	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast32_t")
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$40, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$40, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$40, DW_AT_decl_column(0x16)
$C$DW$T$41	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast8_t")
	.dwattr $C$DW$T$41, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$T$41, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$41, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$41, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$41, DW_AT_decl_column(0x16)
$C$DW$T$42	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least32_t")
	.dwattr $C$DW$T$42, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$T$42, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$42, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$42, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$42, DW_AT_decl_column(0x16)
$C$DW$T$43	.dwtag  DW_TAG_typedef, DW_AT_name("uintptr_t")
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$43, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$43, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$43, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$43, DW_AT_decl_column(0x1a)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x04)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned long")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x04)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x08)
$C$DW$T$44	.dwtag  DW_TAG_typedef, DW_AT_name("int64_t")
	.dwattr $C$DW$T$44, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$44, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$44, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$44, DW_AT_decl_line(0x32)
	.dwattr $C$DW$T$44, DW_AT_decl_column(0x21)
$C$DW$T$45	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast64_t")
	.dwattr $C$DW$T$45, DW_AT_type(*$C$DW$T$44)
	.dwattr $C$DW$T$45, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$45, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$45, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$45, DW_AT_decl_column(0x17)
$C$DW$T$46	.dwtag  DW_TAG_typedef, DW_AT_name("int_least64_t")
	.dwattr $C$DW$T$46, DW_AT_type(*$C$DW$T$44)
	.dwattr $C$DW$T$46, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$46, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$46, DW_AT_decl_line(0x40)
	.dwattr $C$DW$T$46, DW_AT_decl_column(0x17)
$C$DW$T$47	.dwtag  DW_TAG_typedef, DW_AT_name("intmax_t")
	.dwattr $C$DW$T$47, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$47, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$47, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$47, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$47, DW_AT_decl_column(0x20)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x08)
$C$DW$T$48	.dwtag  DW_TAG_typedef, DW_AT_name("uint64_t")
	.dwattr $C$DW$T$48, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$48, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$48, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$48, DW_AT_decl_line(0x33)
	.dwattr $C$DW$T$48, DW_AT_decl_column(0x20)
$C$DW$T$49	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast64_t")
	.dwattr $C$DW$T$49, DW_AT_type(*$C$DW$T$48)
	.dwattr $C$DW$T$49, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$49, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$49, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$T$49, DW_AT_decl_column(0x16)
$C$DW$T$50	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least64_t")
	.dwattr $C$DW$T$50, DW_AT_type(*$C$DW$T$48)
	.dwattr $C$DW$T$50, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$50, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$50, DW_AT_decl_line(0x41)
	.dwattr $C$DW$T$50, DW_AT_decl_column(0x16)
$C$DW$T$51	.dwtag  DW_TAG_typedef, DW_AT_name("uintmax_t")
	.dwattr $C$DW$T$51, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$51, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$51, DW_AT_decl_file("S:/ti/ccsv6/tools/compiler/arm_5.1.6/include/stdint.h")
	.dwattr $C$DW$T$51, DW_AT_decl_line(0x57)
	.dwattr $C$DW$T$51, DW_AT_decl_column(0x20)
$C$DW$T$16	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$16, DW_AT_name("float")
	.dwattr $C$DW$T$16, DW_AT_byte_size(0x04)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
	.dwattr $C$DW$CU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

$C$DW$CIE	.dwcie 14
	.dwcfi	cfa_register, 13
	.dwcfi	cfa_offset, 0
	.dwcfi	undefined, 0
	.dwcfi	undefined, 1
	.dwcfi	undefined, 2
	.dwcfi	undefined, 3
	.dwcfi	same_value, 4
	.dwcfi	same_value, 5
	.dwcfi	same_value, 6
	.dwcfi	same_value, 7
	.dwcfi	same_value, 8
	.dwcfi	same_value, 9
	.dwcfi	same_value, 10
	.dwcfi	same_value, 11
	.dwcfi	undefined, 12
	.dwcfi	undefined, 13
	.dwcfi	undefined, 14
	.dwcfi	undefined, 14
	.dwcfi	undefined, 7
	.dwcfi	undefined, 64
	.dwcfi	undefined, 65
	.dwcfi	undefined, 66
	.dwcfi	undefined, 67
	.dwcfi	undefined, 68
	.dwcfi	undefined, 69
	.dwcfi	undefined, 70
	.dwcfi	undefined, 71
	.dwcfi	undefined, 72
	.dwcfi	undefined, 73
	.dwcfi	undefined, 74
	.dwcfi	undefined, 75
	.dwcfi	undefined, 76
	.dwcfi	undefined, 77
	.dwcfi	undefined, 78
	.dwcfi	undefined, 79
	.dwcfi	same_value, 80
	.dwcfi	same_value, 81
	.dwcfi	same_value, 82
	.dwcfi	same_value, 83
	.dwcfi	same_value, 84
	.dwcfi	same_value, 85
	.dwcfi	same_value, 86
	.dwcfi	same_value, 87
	.dwcfi	same_value, 88
	.dwcfi	same_value, 89
	.dwcfi	same_value, 90
	.dwcfi	same_value, 91
	.dwcfi	same_value, 92
	.dwcfi	same_value, 93
	.dwcfi	same_value, 94
	.dwcfi	same_value, 95
	.dwendentry
	.dwendtag $C$DW$CU

