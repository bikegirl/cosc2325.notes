all:
	cd lectures && make html

clean:
	cd lectures && make clean

pdf:
	cd lectures && make latexpdf

venv:
	virtualenv _venv

reqs:
	pip install -r requirements.txt

