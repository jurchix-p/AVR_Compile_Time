	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4125:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	xor	eax, eax
	mov	BYTE PTR _ZL4dirA[rip], -1
	mov	BYTE PTR _ZL4dirD[rip], -1
	mov	BYTE PTR _ZL4dirC[rip], -1
	mov	BYTE PTR _ZL4dirB[rip], -1
	mov	BYTE PTR _ZL4outA[rip], 3
	mov	BYTE PTR _ZL4outD[rip], -40
	mov	BYTE PTR _ZL4outC[rip], -86
	mov	BYTE PTR _ZL4outB[rip], -92
	add	rsp, 40
	ret
	.seh_endproc
.lcomm _ZL4dirD,1,1
.lcomm _ZL4dirC,1,1
.lcomm _ZL4dirB,1,1
.lcomm _ZL4dirA,1,1
.lcomm _ZL3inD,1,1
.lcomm _ZL3inC,1,1
.lcomm _ZL3inB,1,1
.lcomm _ZL3inA,1,1
.lcomm _ZL4outD,1,1
.lcomm _ZL4outC,1,1
.lcomm _ZL4outB,1,1
.lcomm _ZL4outA,1,1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r3) 15.2.0"
