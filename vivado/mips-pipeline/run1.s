00400000: 20080000 ; <input:2> addi $t0, $zero, 0
00400004: 20090064 ; <input:3> addi $t1, $zero, 100
00400008: 200a00c8 ; <input:4> addi $t2, $zero, 200
0040000c: 200b0001 ; <input:5> addi $t3, $zero, 1
00400010: 20100000 ; <input:6> addi $s0, $zero, 0
00400014: <LABEL_INIT> ; <input:9> LABEL_INIT:
00400014: ae0b0000 ; <input:10> sw $t3, 0($s0)
00400018: ae0b0064 ; <input:11> sw $t3, 100($s0)
0040001c: ae0000c8 ; <input:12> sw $zero, 200($s0)
00400020: 22100004 ; <input:13> addi $s0, $s0, 4
00400024: 1609fffb ; <input:14> bne $s0, $t1, LABEL_INIT
00400028: 20040000 ; <input:19> addi $a0, $zero, 0# init i
0040002c: 21070005 ; <input:20> addi $a3, $t0, 5
00400030: 20150014 ; <input:21> addi $s5, $zero, 20
00400034: 21100000 ; <input:22> addi $s0, $t0, 0
00400038: 21110000 ; <input:23> addi $s1, $t0, 0
0040003c: 21120000 ; <input:24> addi $s2, $t0, 0
00400040: <LOOP_I> ; <input:28> LOOP_I:
00400040: 10870018 ; <input:29> beq $a0, $a3, LOOP_I_END
00400044: 22130000 ; <input:30> addi $s3, $s0, 0 # a init for j
00400048: 20050000 ; <input:31> addi $a1, $zero, 0# init j
0040004c: 20110000 ; <input:32> addi $s1, $zero, 0# b reset in i
00400050: <LOOP_J> ; <input:33> LOOP_J:
00400050: 10a70012 ; <input:34> beq $a1, $a3, LOOP_J_END
00400054: 22700000 ; <input:35> addi $s0, $s3, 0 # a reset in j
00400058: 22340000 ; <input:36> addi $s4, $s1, 0 # b init in j
0040005c: 20060000 ; <input:38> addi $a2, $zero, 0# init k
00400060: <LOOP_K> ; <input:39> LOOP_K:
00400060: 10c7000a ; <input:40> beq $a2, $a3, LOOP_K_END
00400064: 8e0c0000 ; <input:42> lw $t4, 0($s0)
00400068: 8e2d0064 ; <input:43> lw $t5, 100($s1)
0040006c: 8e4e00c8 ; <input:44> lw $t6, 200($s2)
00400070: 018d5824 ; <input:45> and $t3, $t4, $t5
00400074: 01cb7025 ; <input:46> or $t6, $t6, $t3
00400078: ae4e00c8 ; <input:47> sw $t6, 200($s2)
0040007c: 20c60001 ; <input:49> addi $a2, $a2, 1 # k++
00400080: 22100004 ; <input:50> addi $s0, $s0, 4 # a update in k
00400084: 20000000 ; <input:51> addi $s1, $s1, $s5# b update in k
00400088: 08100018 ; <input:52> j LOOP_K
0040008c: <LOOP_K_END> ; <input:54> LOOP_K_END:
0040008c: 20a50001 ; <input:56> addi $a1, $a1, 1 # j++
00400090: 00000020 ; <input:57> add $s2, $s2, 4 # c update in j
00400094: 22910004 ; <input:58> addi $s1, $s4, 4 # b reset in j
00400098: 08100014 ; <input:59> j LOOP_J
0040009c: <LOOP_J_END> ; <input:61> LOOP_J_END:
0040009c: 20840001 ; <input:63> addi $a0, $a0, 1 # i++
004000a0: 08100010 ; <input:64> j LOOP_I
004000a4: <LOOP_I_END> ; <input:65> LOOP_I_END:
004000a4: 2010012c ; <input:67> addi $s0, $zero, 300
004000a8: 2011022c ; <input:68> addi $s1, $zero, 556
004000ac: <LOOP_FLUSH> ; <input:70> LOOP_FLUSH:
004000ac: 12110003 ; <input:71> beq $s0, $s1, LOOP_FLUSH_END
004000b0: 8e120000 ; <input:72> lw $s2, 0($s0)
004000b4: 22100004 ; <input:73> addi $s0, $s0, 4
004000b8: 0810002b ; <input:74> j LOOP_FLUSH
004000bc: <LOOP_FLUSH_END> ; <input:75> LOOP_FLUSH_END:
; UNRECOGNIZED INSTRUCTION ; <input:76> nop
; UNRECOGNIZED INSTRUCTION ; <input:77> nop
; UNRECOGNIZED INSTRUCTION ; <input:78> nop
; UNRECOGNIZED INSTRUCTION ; <input:79> nop
; UNRECOGNIZED INSTRUCTION ; <input:80> nop
; UNRECOGNIZED INSTRUCTION ; <input:81> nop
