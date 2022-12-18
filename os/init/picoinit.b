implement Init;

include "sys.m";
	sys: Sys;
	print: import sys;
include "draw.m";
include "sh.m";

Init: module
{
	init: fn();
};


init()
{
	sys = load Sys Sys->PATH;
	sys->print("Hello world! from Dis!\n");

	sys->bind("/", "/", Sys->MREPL);
	dobind("#p", "/prog", sys->MREPL);	# prog
	dobind("#c", "/dev", sys->MREPL); 	# console
	sys->bind("#d", "/fd", Sys->MREPL);
	sys->bind("#e", "/env", sys->MREPL|sys->MCREATE);	# environment
	
	sys->print("binds done\n");
	sh := load Command "/dis/pwd.dis";
	if(sh == nil){
		err(sys->sprint("can't load %s: %r", Sh->PATH));
	}
	
	sys->print("loaded module.dis\n");
	spawn sh->init(nil, nil);
	sys->print("spawned\n");
}

err(s: string)
{
	sys->fprint(sys->fildes(2), "init: %s\n", s);
}

dobind(f, t: string, flags: int)
{
	if(sys->bind(f, t, flags) < 0)
		err(sys->sprint("can't bind %s on %s: %r", f, t));
}
