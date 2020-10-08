build: redcore

clean:
	rm redcore
	rm testSend
	
redcore:
	gcc redcore.c redpacket.c route.c redhost.c redinterface.c redprotocol.c redctl.c redprocessor.c -o redcore -Wconversion -Wsign-compare

testSend:
	gcc testSend.c redpacket.c -o testSend
