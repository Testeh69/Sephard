TARGET = main

SRC = main.cpp\
  	utils/json_utils.cpp\
	utils/curl_utils.cpp\
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