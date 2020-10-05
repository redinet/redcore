build: redcore redctl

clean:
	rm redcore
	rm redctl
	rm testSend
	
redcore:
	gcc redcore.c redpacket.c route.c redhost.c redinterface.c -o redcore -Wconversion -Wsign-compare

redctl:
	gcc redctl.c -o redctl

testSend:
	gcc testSend.c redpacket.c -o testSend
