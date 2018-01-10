# Programa que hace la división entre dos números ocupando
# ciclos para el calculo mediante multiplicación con el fin de no utilizar
# la funcion división predefinida.
.data
	Dato1 :	.word 199 	
	Dato2 :	.word 7		
	
.text
	lw $t0 Op1	
	lw $t1 Op2	
	li $t2 0	
	li $t4 1	
	add $t2 $t2 $t4 
# Ciclo donde se ejecuta la multiplicación
do : 	
	mul $t3 $t1 $t2	
	bgt $t3 $t0 exit 
	addi $t2 $t4 1	
	move $t4 $t2	
	j do		
exit :	
	li $t2 1	
	sub $v0 $t4 $t2	
	mul $t5 $v0 $t1	
	sub $v1 $t0 $t5	
