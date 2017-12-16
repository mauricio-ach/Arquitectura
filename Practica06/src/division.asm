#Programa que regresa el cociente y residuo de una division
	.data
	
dividendo:	.word	120
divisor:	.word   10
cociente:	.word	0
residuo:	.word	0
temp:		.word 	0

	.text
	
	lw	$t0,dividendo
	lw	$t1,divisor
	lw	$t2,cociente
	lw	$t3,residuo
	lw	$t4,temp
	
diiv:	ble	$t0, $t1, end		#if dividendo <= divisor termina
	sub	$t4, $t0, $t1		# guarda en temp la resta dividendo- divisor
	move 	$t0, $t4		# actualiza el valor del dividendo
	addi	$t2, $t2, 1		# se le suma +1 al cociente
	j	diiv			# llamada recursiva

end:	addi	$t2, $t2, 1		
	move	$v0, $t2		# Valor del cociente
	move	$v1, $t0		# Valor del residuo
	

