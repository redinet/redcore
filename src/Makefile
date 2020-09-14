build: redcore redctl
	

redcore:
	gcc redcore.c route.c redpacket.c -o redcore

redctl:
	gcc redctl.c -o redctl

testSend:
	gcc testSend.c redpacket.c -o testSend
