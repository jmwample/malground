

new: clean packer

packer: packer.c
	$(CC) -Wall $^ -o $@

clean: 
	$(RM) *.o packer
