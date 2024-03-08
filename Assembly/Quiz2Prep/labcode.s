.pos 0x100
code:

ld $x, r0
ld 0(r0), r0        # r0 = x
bgt r0, next_cond
br else
next_cond: ld $10, r1
mov r0, r2
not r2
inc r2              # r2 = -x
add r2, r1          # r1 = 10-x
bgt r1, if
else: ld $0, r7
br endif
if: mov r0, r7
endif: ld $y, r5
st r7, 0(r5)
halt


.pos 0x1000
static:
x:  .long 20
y: .long 10
z: .long 0