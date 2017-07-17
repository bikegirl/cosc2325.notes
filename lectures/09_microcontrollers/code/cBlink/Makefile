# Makefile for aBuzz

TARGET	= cBlink

CSRCS 	= $(wildcard *.c)
INTTBL	= FALSE

# board definition
MCU	= atmega328p
F_CPU	= 16000000

# uncomment one of these linesand check for your system:
PORT	= COM4
#PORT	= /dev/ttyACM0
#PORT	= /dev/cu.usbmodem1411

# uncomment one of these lines
MAKE_BASE = ../
#MAKE_BASE = /usr/local/
include $(MAKE_BASE)include/AVRMakefile.mak
