.pos 0x1000
code:
ld $x, r0       # r0 = address of x
ld $0, r1       # r1 = 0
st r1, 0(r0)    # x = 0 
ld 0(r0), r1    # r1 = x = 0
ld $y, r2       # r2 = address of y
ld 0(r2), r3    # r3 = y 
mov r3, r4
not r4
inc r4          # r4 = -y
add r1, r4      # r4 = x-y
loop: beq r4, end_loop
bgt r4, end_loop
dec r3
inc r1
inc r4
br loop
end_loop: st r3, 0(r2)
st r1, 0(r0)


.pos 0x2000
x:  .long 0
y:  .long 10





