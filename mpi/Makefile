s=
obj=$(s:.c=.o)
executable=exec
compiler=mpicc
p=2
h=

.PHONY:run

run:$(executable)
ifdef h
	@mpirun -np $(p) -hostfile $(h) $(executable)
else
	@mpirun -np $(p) $(executable)
endif

$(executable):$(obj)
	@$(compiler) -o $(executable) $(obj)

$(obj):$(s)
	@$(compiler) -c $(s)

clean:
	@rm -f $(obj) $(executable)



