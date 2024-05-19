TARGET = target 
OBJS = main.o

TMP = share_mmap.c


target:$(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJS):$(TMP)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)