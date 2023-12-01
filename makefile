src=file.c
obj=$(src:.c=.o)
exec=exec
Compiler=mpicc
process=2
run:$(exec)
	@mpirun -np $(process) $(exec)

$(exec):$(obj)

	@$(Compiler) -o $(exec) $(obj)

$(obj):$(src)
	@$(Compiler) -c $(src)

clean:
	@rm -f $(obj) $(exec)
