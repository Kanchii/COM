.class public JVM
.super java/lang/Object

.method public <init>()V
	aload_0

	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static fat(I)I
	.limit stack 10
	.limit locals 3
	iload 0
	iconst_1
	if_icmple F1
	goto F2
F1:
	iconst_1
	istore 1
	goto F3
F2:
	iload 0
	iconst_1
	isub
	invokestatic JVM.fat(I)I
	istore 2
	iload 0
	iload 2
	imul
	istore 1
F3:
	iload 1
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 10
	.limit locals 4
	new java/util/Scanner
	dup
	getstatic java/lang/System/in Ljava/io/InputStream;
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
	astore 3
	aload 3
	invokevirtual java/util/Scanner/nextInt()I
	istore 1
	iload 1
	invokestatic JVM.fat(I)I
	istore 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "Fatorial("
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/print(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc ") = "
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 2
	invokevirtual java/io/PrintStream/print(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	return
.end method
