implement Init;

include "sys.m";
	sys: Sys;
	print: import sys;

Init: module
{
	init: fn();
};


init()
{
	sys = load Sys Sys->PATH;
	sys->print("Hello world! from Dis!\n");
}

