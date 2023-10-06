extern unsigned char root11code[];
extern int root11len;
extern unsigned char root12code[];
extern int root12len;
extern unsigned char root13code[];
extern int root13len;
extern unsigned char root14code[];
extern int root14len;
extern unsigned char root15code[];
extern int root15len;
extern unsigned char root16code[];
extern int root16len;
extern unsigned char root17code[];
extern int root17len;
extern unsigned char root18code[];
extern int root18len;
extern unsigned char root19code[];
extern int root19len;
extern unsigned char root20code[];
extern int root20len;
extern unsigned char root21code[];
extern int root21len;
extern unsigned char root22code[];
extern int root22len;
extern unsigned char root23code[];
extern int root23len;
extern unsigned char root24code[];
extern int root24len;
extern unsigned char root25code[];
extern int root25len;
extern unsigned char root26code[];
extern int root26len;
extern unsigned char root27code[];
extern int root27len;
extern unsigned char root28code[];
extern int root28len;
extern unsigned char root29code[];
extern int root29len;
int rootmaxq = 30;
Dirtab roottab[30] = {
	"",	{0, 0, QTDIR},	 0,	0555,
	"chan",	{1, 0, QTDIR},	 0,	0555,
	"dev",	{2, 0, QTDIR},	 0,	0555,
	"dis",	{3, 0, QTDIR},	 0,	0555,
	"env",	{4, 0, QTDIR},	 0,	0555,
	"fd",	{5, 0, QTDIR},	 0,	0555,
	"net",	{6, 0, QTDIR},	 0,	0555,
	"prog",	{7, 0, QTDIR},	 0,	0555,
	"osinit.dis",	{8, 0, QTFILE},	 0,	0444,
	"math",	{9, 0, QTDIR},	 0,	0555,
	"tiny",	{10, 0, QTDIR},	 0,	0555,
	"lib",	{11, 0, QTDIR},	 0,	0555,
	"ls.dis",	{12, 0, QTFILE},	 0,	0444,
	"ps.dis",	{13, 0, QTFILE},	 0,	0444,
	"ns.dis",	{14, 0, QTFILE},	 0,	0444,
	"cat.dis",	{15, 0, QTFILE},	 0,	0444,
	"pwd.dis",	{16, 0, QTFILE},	 0,	0444,
	"echo.dis",	{17, 0, QTFILE},	 0,	0444,
	"cd.dis",	{18, 0, QTFILE},	 0,	0444,
	"bind.dis",	{19, 0, QTFILE},	 0,	0444,
	"mount.dis",	{20, 0, QTFILE},	 0,	0444,
	"blink.dis",	{21, 0, QTFILE},	 0,	0444,
	"sh.dis",	{22, 0, QTFILE},	 0,	0444,
	"readdir.dis",	{23, 0, QTFILE},	 0,	0444,
	"workdir.dis",	{24, 0, QTFILE},	 0,	0444,
	"daytime.dis",	{25, 0, QTFILE},	 0,	0444,
	"bufio.dis",	{26, 0, QTFILE},	 0,	0444,
	"string.dis",	{27, 0, QTFILE},	 0,	0444,
	"arg.dis",	{28, 0, QTFILE},	 0,	0444,
	"env.dis",	{29, 0, QTFILE},	 0,	0444,
};
Rootdata rootdata[30] = {
	0,	 &roottab[1],	 8,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 &roottab[9],	 13,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 root11code,	 0,	 &root11len,
	3,	 nil,	 0,	 nil,
	3,	 &roottab[22],	 1,	nil,
	3,	 &roottab[23],	 7,	nil,
	3,	 root13code,	 0,	 &root13len,
	3,	 root14code,	 0,	 &root14len,
	3,	 root15code,	 0,	 &root15len,
	3,	 root16code,	 0,	 &root16len,
	3,	 root17code,	 0,	 &root17len,
	3,	 root18code,	 0,	 &root18len,
	3,	 root19code,	 0,	 &root19len,
	3,	 root20code,	 0,	 &root20len,
	3,	 root21code,	 0,	 &root21len,
	3,	 root22code,	 0,	 &root22len,
	10,	 root12code,	 0,	 &root12len,
	11,	 root23code,	 0,	 &root23len,
	11,	 root24code,	 0,	 &root24len,
	11,	 root25code,	 0,	 &root25len,
	11,	 root26code,	 0,	 &root26len,
	11,	 root27code,	 0,	 &root27len,
	11,	 root28code,	 0,	 &root28len,
	11,	 root29code,	 0,	 &root29len,
};
