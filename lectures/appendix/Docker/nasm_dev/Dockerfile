from alpine
RUN apk --no-cache add \
    nasm gcc musl-dev

ADD . /docs
WORKDIR /docs

CMD ['make -f Makefile.docker run']
