.text
.global test_func
.global add_func
.global switch_func

//C prototype int test_func(void);
test_func:
	mov $0x1, %rax
	ret

// C prototype: int add_func(int, int)
add_func:
	add %rdi, %rsi
	mov %rsi, %rax
	ret

// C prototype: void switch_func(void (*)(int), int); 

switch_func:
	mov %rdi, (%rsp)
	movq %rsi, %rdi
	ret
