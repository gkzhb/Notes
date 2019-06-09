.main
  # a: $t0 0, b: $t1 100, c: $t2 200
  # $t3 1
  addi $t0, $zero, 0
  addi $t1, $zero, 100
  addi $t2, $zero, 200
  addi $t3, $zero, 1
  addi $s0, $zero, 0

  # First Loop to Initiate Arrays
LABEL_INIT:
  sw $t3, 0($s0)
  sw $t3, 100($s0)
  sw $zero, 200($s0)
  addi $s0, $s0, 4
  bne $s0, $t1, LABEL_INIT

  # i: $a0, j: $a1, k: $a2
  # $a3 = 5 $s5 = 5*4
  # ptra: $s0, ptrb: $s1, ptrc: $s2
  addi $a0, $zero, 0# init i
  addi $a3, $t0, 5
  addi $s5, $zero, 20
  addi $s0, $t0, 0
  addi $s1, $t0, 0
  addi $s2, $t0, 0

  # tmp: $t3, a[i][k]: $t4, b[k][j]: $t5, c[i][j]: $t6
  # tmp_ptr: $s3, $s4
LOOP_I:
  beq $a0, $a3, LOOP_I_END
  addi $s3, $s0, 0  # a init for j
  addi $a1, $zero, 0# init j
  addi $s1, $zero, 0# b reset in i
LOOP_J:
  beq $a1, $a3, LOOP_J_END
  addi $s0, $s3, 0  # a reset in j
  addi $s4, $s1, 0  # b init in j
  
  addi $a2, $zero, 0# init k
LOOP_K:
  beq $a2, $a3, LOOP_K_END

  lw $t4, 0($s0)
  lw $t5, 100($s1)
  lw $t6, 200($s2)
  and $t3, $t4, $t5
  or $t6, $t6, $t3
  sw $t6, 200($s2)

  addi $a2, $a2, 1  # k++
  addi $s0, $s0, 4  # a update in k
  addi $s1, $s1, $s5# b update in k
  j LOOP_K

LOOP_K_END:

  addi $a1, $a1, 1  # j++
  add $s2, $s2, 4   # c update in j
  addi $s1, $s4, 4  # b reset in j
  j LOOP_J
  
LOOP_J_END:

  addi $a0, $a0, 1  # i++
  j LOOP_I
LOOP_I_END:

  addi $s0, $zero, 300
  addi $s1, $zero, 556

LOOP_FLUSH:
  beq $s0, $s1, LOOP_FLUSH_END
  lw $s2, 0($s0)
  addi $s0, $s0, 4
  j LOOP_FLUSH
LOOP_FLUSH_END:
  nop
  nop
  nop
  nop
  nop
  nop

