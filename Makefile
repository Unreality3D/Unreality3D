all:
	cd indie-studio; mkdir build; cd build; cmake ../; make -j4; cd ../../

clean:
	cd indie-studio; cd build; make clean

re:	clean all