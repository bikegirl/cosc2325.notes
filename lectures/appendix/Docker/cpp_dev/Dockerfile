FROM alpine:latest
RUN apk update && \
    apk add \
        g++ \ 
        make \
        musl-dev
COPY app/ app/
WORKDIR /app
