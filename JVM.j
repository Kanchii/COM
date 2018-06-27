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
	bipush 53
	istore 1
	iconst_2
	istore 2
	iconst_1
	istore 4
	iload 2
	iload 1
	if_icmplt F1
	goto F2
F1:
	iconst_0
	istore 3
	iload 3
	iload 1
	if_icmplt F3
	goto F4
F3:
	iload 3
	iload 2
	iadd
	istore 3
	iload 3
	iload 1
	if_icmplt F3
	goto F4
F4:
	iload 3
	iload 1
	if_icmpeq F5
	goto F6
F5:
	iconst_0
	istore 4
	iload 1
	istore 2
F6:
	iload 2
	iconst_1
	iadd
	istore 2
	iload 2
	iload 1
	if_icmplt F1
	goto F2
F2:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/print(I)V
	iload 4
	iconst_1
	if_icmpeq F7
	goto F8
F7:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " eh primo!!\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto F9
F8:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " nao eh primo!!\n"
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
F9:
	return
.end method
