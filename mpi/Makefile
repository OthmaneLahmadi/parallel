src=
obj=$(src:.c=.o)
exec=exec
Compiler=mpicc
process=2
host_=
run:$(exec)
ifdef host_
	mpirun -np $(process) -hostfile $(host_) $(exec)
else
	mpirun -np $(process) $(exec)
endif

$(exec):$(obj)

	$(Compiler) -o $(exec) $(obj)

$(obj):$(src)
	@$(Compiler) -c $(src)

clean:
	@rm -f $(obj) $(exec)
