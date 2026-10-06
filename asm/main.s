	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4119:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	mov	BYTE PTR _ZL4outA[rip], 3
	mov	BYTE PTR _ZL4outD[rip], -40
	mov	BYTE PTR _ZL4outC[rip], -86
	mov	BYTE PTR _ZL4outB[rip], -92
	movzx	eax, BYTE PTR _ZL4outA[rip]
	movzx	eax, BYTE PTR _ZL4outD[rip]
	movzx	eax, BYTE PTR _ZL4outC[rip]
	movzx	eax, BYTE PTR _ZL4outB[rip]
	xor	eax, eax
	add	rsp, 40
	ret
	.seh_endproc
.lcomm _ZL4outD,1,1
.lcomm _ZL4outC,1,1
.lcomm _ZL4outB,1,1
.lcomm _ZL4outA,1,1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r3) 15.2.0"
