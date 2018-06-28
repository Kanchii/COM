.class public JVM
.super java/lang/Object

.method public <init>()V
	aload_0

	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static isPrimo(II)I
	.limit stack 10
	.limit locals 4
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "Testando "
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 0
	invokevirtual java/io/PrintStream/print(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " dividido por "
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/print(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 1
	iconst_1
	if_icmple F1
	goto F2
F1:
	iconst_1
	istore 2
	goto F3
F2:
	iload 0
	istore 3
	iload 3
	iconst_0
	if_icmpgt F4
	goto F5
F4:
	iload 3
	iload 1
	isub
	istore 3
	iload 3
	iconst_0
	if_icmpgt F4
	goto F5
F5:
	iload 3
	iconst_0
	if_icmpeq F6
	goto F7
F6:
	iconst_0
	istore 2
	goto F8
F7:
	iload 0
	iload 1
	iconst_1
	isub
	invokestatic JVM.isPrimo(II)I
	istore 2
F8:
F3:
	iload 2
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 10
	.limit locals 3
	ldc 995
	istore 1
	iload 1
	iload 1
	iconst_2
	idiv
	invokestatic JVM.isPrimo(II)I
	istore 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/print(I)V
	iload 2
	iconst_0
	if_icmpeq F9
	goto F10
F9:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " nao eh primo!\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto F11
F10:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " eh primo!\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
F11:
	return
.end method
