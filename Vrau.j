.class public Vrau
.super java/lang/Object

.method public <init>()V
	aload_0
	
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 3
	.limit locals 4
	iconst_1
	istore 1
	bipush 20
	istore 2
	iload 2
	iload 1
	iconst_2
	imul
	iadd
	i2f
	fstore 3
	iload 2
	i2f
	iconst_4
	i2f
	ldc 6.000000
	fadd
	fmul
	fload 3
	fsub
	f2i
	istore 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload_1
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
