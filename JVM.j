.class public JVM
.super java/lang/Object

.method public <init>()V
	aload_0

	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 10
	.limit locals 10
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "Valor: "
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iconst_5
	istore 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 3
	invokevirtual java/io/PrintStream/print(I)V
	return
.end method
