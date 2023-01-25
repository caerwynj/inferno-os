implement Init;

include "sys.m";
	sys: Sys;
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
	
	setsysname("ipico");			# set system name
	sys->chdir("/");

	sh := load Command "/dis/tiny/sh.dis";
	if(sh == nil){
		err(sys->sprint("can't load %s: %r", Sh->PATH));
	}
	
	sys->print("loaded module.dis\n");
	sys->fprint(sys->fildes(2), "print to stderr\n");
	
	spawn sh->init(nil, "sh"  :: nil);
	sys->print("spawned\n");
	
}

setsysname(def: string)
{
	v := array of byte def;

	fd := sys->open("/env/sysname", sys->OREAD);
	if(fd != nil){
		buf := array[Sys->NAMEMAX] of byte;
		nr := sys->read(fd, buf, len buf);
		while(nr > 0 && buf[nr-1] == byte '\n')
			nr--;
		if(nr > 0)
			v = buf[0:nr];
	}
	fd = sys->open("/dev/sysname", sys->OWRITE);
	if(fd != nil)
		sys->write(fd, v, len v);
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
