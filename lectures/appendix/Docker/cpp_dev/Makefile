# Makefile for docker experiments
BASE_IMG	:=	alpine
PROJECT		:=	$(shell basename $(PWD))

.PHONY:	pull
pull:
	docker pull $(BASE_IMG)

.PHONY:	build
build:
	docker build -t $(PROJECT) .

.PHONY:	clean
clean:
	docker rmi -f $(PROJECT)

.PHONY: shell
shell:
	docker run -it --rm $(PROJECT) /bin/ash
