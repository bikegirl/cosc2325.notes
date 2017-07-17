# ref: http://datakurre.pandala.org/2016/04/evolution-of-our-makefile-for-docker.html
#
BASE_IMG	:= alpine:latest
DH_USER 	:=  rblack42
DOCKER_HUB  :=  docker.io
PROJ_NAME  := $(shell basename $(PWD))

.PHONY:	all
all:
	@echo $(PROJ_NAME)

.PHONY:	pull
pull:
	docker pull $(BASE_IMG)

.PHONY:	clean
clean:
	docker ps -a -q | xargs docker rm
	docker images -q | xargs docker rmi

.PHONY:	build
build:	
	docker build -t "$(PROJ_NAME)" .

.PHONY:	run
run:
	docker run -it i$(PROJ_NAME) /bin/ash

