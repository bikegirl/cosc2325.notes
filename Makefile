LOCALDIR    := /Users/rblack/_github/cosc2325.notes/lectures/_build/html/
REMOTEDIR   := www/classes/summer2017/cosc2325-001/
SSHPORT     := 5224
    

all:
	cd lectures && make html

clean:
	cd lectures && make clean

pdf:
	cd lectures && make latexpdf

venv:
	python3 -m venv _venv

reqs:
	pip install -r requirements.txt

sync:
	rsync -rvz -e 'ssh -p $(SSHPORT)' $(LOCALDIR) rblack@www.co-pylit.org:$(REMOTEDIR)

