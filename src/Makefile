build: redcore redctl

clean:
	rm redcore
	rm redctl
	rm testSend
	
redcore:
	gcc redcore.c route.c redpacket.c redhost.c -o redcore

redctl:
	gcc redctl.c -o redctl

testSend:
	gcc testSend.c redpacket.c -o testSend
