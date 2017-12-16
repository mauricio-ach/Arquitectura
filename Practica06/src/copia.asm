	.data 

a: 	.word   7
c: 	.word 	3
	.text
	
	lw   	$t0, a
	lw 	$t1, c
	
loop:	or 	$t0, $t0, $t1
	or      $t1, $t0, $t1
end:	or	$v0, $t1, $t0