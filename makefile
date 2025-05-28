TARGET = main

SRC = main.cpp\
  	json_utils.cpp\
	curl_utils.cpp\
	-lcurl

${TARGET} : ${SRC}
	g++ ${SRC} -o ${TARGET}


go:
	./main



clean:
	rm -f $(TARGET)

#make pour compiler le projet
#make go pour lancer le projet compiler
#make clean pour supprimer le projet